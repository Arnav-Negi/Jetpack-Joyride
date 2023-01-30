#include "game.h"

SpriteRenderer *Renderer;
TextRenderer *Text;

Game::Game(unsigned int width, unsigned int height)
        : State(GAME_ACTIVE), Keys(), Width(width), Height(height) {

}

Game::~Game() {
    delete Renderer;
}

void Game::Init() {
//    bzero(this->Keys, 1024 * sizeof(bool));

    // load shaders
    ResourceManager::LoadShader("/home/arnav/courses/4/cg/ass1/src/shaders/sprite.vs",
                                "/home/arnav/courses/4/cg/ass1/src/shaders/sprite.fs", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
                                      static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Shader MyShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(MyShader);
    // load textures
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/mario.png", true, "sprite");
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/BG.png", true, "background");
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/coin.png", true, "coin");
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/laser.png", true, "laser");

    Text = new TextRenderer(this->Width, this->Height);
    Text->Load("/home/arnav/courses/4/cg/ass1/src/textures/OCRAEXT.TTF", 24);

    this->Lvl = 0;

    this->SpriteAcc = -1000;
    Renderer->Position = glm::vec2(100, this->Height - Renderer->Size.y);
    Renderer->Velocity = glm::vec2(0, 0);
    Renderer->Rotation = 0;
    Renderer->Size = glm::vec2(80, 80);
    Renderer->Color = glm::vec3(1, 1, 1);

    this->InitLvl(0);
}

void Game::InitLvl(int lvl) {
    this->Lvl = lvl;
    this->BgDistance = 0;
    this->Coins.clear();
    this->SpawnCoins();

    this->Zappers.clear();
    this->SpawnZappers();

    if (lvl == 0) {
        this->BgVelocity = 0.02;
        this->Score = 0;
    }
    else if (lvl == 1) {
        this->BgVelocity = 0.03;
    }
    else {
        this->BgVelocity = 0.04;
    }
}

float RandomF(float left, float right) {
    float res = (float) rand() / RAND_MAX;
    return (res * (right - left)) + left;
}

int RandomI(float left, float right) {
    float res = (float) rand() / RAND_MAX;
    return (int) (res * (right - left)) + left;
}

void Game::SpawnCoins() {
    // Coin subunits in sections of length 300 with 50 length buffers in between
    // Subunits of 3 types - zigzag, rectangles, lines

    for (int i = 0; i < 10; i++) {
        float startX = RandomF(0, 50);
        float startY = RandomF(0, this->Height - 100);
        int state = RandomI(0, 3);
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX, startY), 25, glm::vec2(COIN_VEL, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 25, startY + 50), 25, glm::vec2(COIN_VEL, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 50, startY), 25, glm::vec2(COIN_VEL, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 75, startY + 50), 25, glm::vec2(COIN_VEL, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 100, startY), 25, glm::vec2(COIN_VEL, 0),
                               ResourceManager::GetTexture("coin")));
    }
}

void Game::SpawnZappers() {
    for (int i = 0; i < 10; i++) {
        float startX = RandomF(0, 50);
        float startY = RandomF(0, this->Height - 200);
        int state = RandomI(0, 3);
        this->Zappers.push_back(
                new GameObject(glm::vec2(this->Width + i * 350 + startX, startY), glm::vec2(10, 150), ResourceManager::GetTexture("laser"),
                               glm::vec3(1), glm::vec2(COIN_VEL, 0)));
    }
}

bool Game::CheckCollision(BallObject &one, SpriteRenderer &two) // AABB - Circle collision
{
    // get center point circle first
    glm::vec2 center(one.Position + one.Radius);
    // calculate AABB info (center, half-extents)
    glm::vec2 aabb_half_extents(two.Size.x / 2.0f, two.Size.y / 2.0f);
    glm::vec2 aabb_center(
            two.Position.x + aabb_half_extents.x,
            two.Position.y + aabb_half_extents.y
    );
    // get difference vector between both centers
    glm::vec2 difference = center - aabb_center;
    glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
    // add clamped value to AABB_center and we get the value of box closest to circle
    glm::vec2 closest = aabb_center + clamped;
    // retrieve vector between center circle and closest point AABB and check if length <= radius
    difference = closest - center;
    return glm::length(difference) < one.Radius;
}

void Game::Update(float dt) {
    srand(time(NULL));
    float NetAcc = this->SpriteAcc + (this->Keys[GLFW_KEY_SPACE]&&!this->Dead) * 1300;
    Renderer->Velocity.y -= NetAcc * dt;

    if (Renderer->Velocity.y > 0 && (this->Keys[GLFW_KEY_SPACE]&&!this->Dead) ) Renderer->Velocity.y = 0;

    if (Renderer->Velocity.y > 400) Renderer->Velocity.y = 400;
    Renderer->Position += Renderer->Velocity * dt;
    if (Renderer->Position.y > this->Height - Renderer->Size.y) {
        Renderer->Position.y = this->Height - Renderer->Size.y;
        Renderer->Velocity = glm::vec2(0, 0);
    }
    if (Renderer->Position.y < 0) {
        Renderer->Position.y = 0;
        Renderer->Velocity = glm::vec2(0, 0);
    }

    this->BgDistance += this->BgVelocity * dt;

    for (auto coinObj: this->Coins) {
        coinObj->Move(dt, this->Width);
    }
    for (auto zap : this->Zappers) {
        zap->Move(dt, this->Width);
    }

    this->DoCollisions();
}

bool Game::CheckCollision(GameObject &one, SpriteRenderer &two) // AABB - AABB collision
{
    // collision x-axis?
    bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
                      two.Position.x + two.Size.x >= one.Position.x;
    // collision y-axis?
    bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
                      two.Position.y + two.Size.y >= one.Position.y;
    // collision only if on both axes
    return collisionX && collisionY;
}

void Game::DoCollisions() {
    for (auto coin: this->Coins) {
        if (!coin->Destroyed && this->CheckCollision(*coin, *Renderer)) {
            coin->Destroyed = true;
            this->Score++;
            printf("%d\n", this->Score);
        }
    }

    for (auto zap: this->Zappers) {
        if (this->CheckCollision(*zap, *Renderer)) {
            printf("DEAD\n");
            this->Die();
        }
    }
}

void Game::Die() {
    Renderer->Color = glm::vec3(1.0, 0.0, 0.0);
    this->BgVelocity = 0;
    for (auto coin : this->Coins) {
        coin->Velocity = glm::vec2(0,0);
    }
    for (auto zap : this->Zappers) {
        zap->Velocity = glm::vec2(0,0);
    }
    Dead = true;
}

void Game::ProcessInput(float dt) {

}

void Game::Render() {
    Texture2D MyTexture = ResourceManager::GetTexture("sprite");
    Texture2D BGTexture = ResourceManager::GetTexture("background");

    Renderer->shader.SetFloat("BgTranslate", this->BgDistance);
    Renderer->DrawSprite(BGTexture, glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0, glm::vec3(1, 1, 1), 1);
    Renderer->shader.SetFloat("BgTranslate", 0);
    Renderer->DrawSprite(MyTexture,
                         Renderer->Position, Renderer->Size, Renderer->Rotation, Renderer->Color, 0);
    for (auto coinObj: this->Coins) {
        if (!coinObj->Destroyed)
            coinObj->Draw(*Renderer);
    }
    for (auto zap : this->Zappers) {
        zap->Draw(*Renderer);
    }

    Text->RenderText("This is some text", 10, 10, 2, glm::vec3(1.0));
}