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
    // load shaders
    ResourceManager::LoadShader("/home/arnav/courses/4/cg/ass1/src/shaders/sprite.vs",
                                "/home/arnav/courses/4/cg/ass1/src/shaders/sprite.fs", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
                                      static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").Use().SetVector2f("iResolution", glm::vec2(this->Width, this->Height));
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Shader MyShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(MyShader);
    // load textures
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/mario.png", true, "sprite");
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/space.png", true, "background");
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/coin.png", true, "coin");
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/glow.png", false, "glow");


    this->HUD = new GameObject(glm::vec2(0, 0), glm::vec2(this->Width, this->Height / 12),
                               ResourceManager::GetTexture("glow"), glm::vec3(0), glm::vec2(0));

    Text = new TextRenderer(this->Width, this->Height);
    Text->Load("/home/arnav/courses/4/cg/ass1/src/textures/tnr.TTF", 24);

    this->Lvl = 0;
    this->CoinRad = 25;
    this->SpriteAcc = -500;
    Renderer->Position = glm::vec2(100, this->Height - Renderer->Size.y);
    Renderer->Velocity = glm::vec2(0, 0);
    Renderer->Rotation = 0;
    Renderer->Size = glm::vec2(80, 80);
    Renderer->Color = glm::vec3(1, 1, 1);
    this->GameEndTimer = 2;

    this->InitLvl(0);
}

void Game::InitLvl(int lvl) {
    srand(time(NULL));
    this->Lvl = lvl;
    this->FgDistance = 0;

    // Difficulty scaling. ALong with Zapper length
    if (lvl == 0) {
        this->CoinVel = -150;
        this->BgVelocity = 0.03;
        this->LvlLength = 8;
        this->Score = 0;
    } else if (lvl == 1) {
        this->LvlLength = 12;
        this->CoinVel = -200;
        this->BgVelocity = 0.04;
    } else {
        this->LvlLength = 16;
        this->CoinVel = -250;
        this->BgVelocity = 0.05;
    }
    this->LvlDesign.clear();
    this->Zappers.clear();
    this->SpawnZappers();

    this->Coins.clear();
    this->SpawnCoins();
    this->State = GAME_ACTIVE;
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

    for (int i = 0; i < this->LvlLength; i++) {
        float startX = RandomF(0, 2 * this->CoinRad);
        int state = (RandomI(1, 3) + this->LvlDesign[i])%3;
        float startY = this->HUD->Size.y + state*this->Height/3;

        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX, startY), this->CoinRad, glm::vec2(CoinVel, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 25, startY + 50), this->CoinRad,
                               glm::vec2(CoinVel, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 50, startY), this->CoinRad,
                               glm::vec2(CoinVel, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 75, startY + 50), this->CoinRad,
                               glm::vec2(CoinVel, 0),
                               ResourceManager::GetTexture("coin")));
        this->Coins.push_back(
                new BallObject(glm::vec2(this->Width + i * 350 + startX + 100, startY), this->CoinRad,
                               glm::vec2(CoinVel, 0),
                               ResourceManager::GetTexture("coin")));
    }
}

void Game::SpawnZappers() {
    for (int i = 0; i < this->LvlLength; i++) {
        float startX = RandomF(0, 50);
        int HeightLvl = RandomI(0, 3);
        float startY = HeightLvl*this->Height/4 + this->HUD->Size.y + 50;
        int state = RandomI(0, 100);
        this->LvlDesign.push_back(HeightLvl);
        if (state < (this->Lvl + 1) * 20) {
            // rotating
            this->Zappers.push_back(
                    new GameObject(glm::vec2(this->Width + i * 350 + startX, startY),
                                   glm::vec2(20, this->Lvl * 50 + 150),
                                   ResourceManager::GetTexture("glow"),
                                   glm::vec3(1), glm::vec2(CoinVel, 0)));
            this->Zappers.back()->ZapperRigid = false;
            this->Zappers.back()->Rotation = 0;
        } else {
            // rigid
            this->Zappers.push_back(
                    new GameObject(glm::vec2(this->Width + i * 350 + startX, startY),
                                   glm::vec2(20, this->Lvl * 50 + 150),
                                   ResourceManager::GetTexture("glow"),
                                   glm::vec3(1), glm::vec2(CoinVel, 0)));
            this->Zappers.back()->ZapperRigid = true;
            this->Zappers.back()->Rotation = 0;
        }
    }
}

void Game::Update(float dt) {
    float NetAcc = this->SpriteAcc + (this->Pressed && !(this->State == GAME_LOSE)) * 800;
    Renderer->Velocity.y -= NetAcc * dt;

    if (Renderer->Velocity.y > 0 && (this->Pressed && !(this->State == GAME_LOSE)))
        Renderer->Velocity.y = 0;

    if (Renderer->Velocity.y > 400) Renderer->Velocity.y = 400;
    Renderer->Position += Renderer->Velocity * dt;
    if (Renderer->Position.y > this->Height - Renderer->Size.y) {
        Renderer->Position.y = this->Height - Renderer->Size.y;
        Renderer->Velocity = glm::vec2(0, 0);
    }

    if (Renderer->Position.y < this->HUD->Size.y) {
        Renderer->Position.y = this->HUD->Size.y;
        Renderer->Velocity = glm::vec2(0, 0);
    }

    if (this->State == GAME_ACTIVE) {
        this->FgDistance -= CoinVel * dt;
        if (this->FgDistance >= this->LvlLength * 350 + this->Width + 50) {
            if (this->Lvl == 2) this->Win();
            else {
                this->Lvl++;
                this->InitLvl(this->Lvl);
            }
        }
    }

    this->DoCollisions();
    if (this->State == GAME_LOSE) {
        this->BgVelocity = fmax(0, this->BgVelocity - 0.2*dt);
        this->CoinVel = fmin(0, this->CoinVel + 100*dt);
    }

    this->BgDistance += this->BgVelocity * dt;
    for (auto coinObj: this->Coins) {
        coinObj->Move(dt, this->Width, this->CoinVel);
    }
    for (auto zap: this->Zappers) {
        zap->Move(dt, this->Width, this->CoinVel);
    }

    if (this->State == GAME_LOSE) this->GameEndTimer -= dt;
}

void Game::DoCollisions() {
    for (auto coin: this->Coins) {
        if (!coin->Destroyed && this->CheckCollision(*coin, *Renderer)) {
            coin->Destroyed = true;
            this->Score++;
        }
    }

    for (auto zap: this->Zappers) {
        if (zap->ZapperRigid) {
            if (this->CheckCollision(*zap, *Renderer)) {
                if (this->State == GAME_ACTIVE)
                    this->Die();
            }
        }
        else if (this->CheckRotatedCollision(*Renderer, *zap)) {
            if (this->State == GAME_ACTIVE)
                this->Die();
        }
    }
}

void Game::Win() {
    this->State = GAME_WIN;
}

void Game::Die() {
    Renderer->Color = glm::vec3(1.0, 0.0, 0.0);

    this->State = GAME_LOSE;
}

void Game::ProcessInput(float dt) {
    if (this->State != GAME_ACTIVE && this->Keys[GLFW_KEY_ENTER]) {
        this->State = GAME_ACTIVE;
        this->Init();
    }
    this->Pressed = false;
    for (auto key : this->Keys) this->Pressed = this->Pressed or key;
}

void Game::Render() {
    Texture2D MyTexture = ResourceManager::GetTexture("sprite");
    Texture2D BGTexture = ResourceManager::GetTexture("background");

    std::ostringstream Msg;
    std::string LvlMsg, ScoreMsg, DistMsg, LengthMsg;
    Msg << "Lvl: " << this->Lvl + 1;
    LvlMsg = Msg.str();
    Msg.str("");
    Msg.clear();
    Msg << "Score: " << this->Score;
    ScoreMsg = Msg.str();
    Msg.str("");
    Msg.clear();
    Msg << "Covered: " << (int) this->FgDistance;
    DistMsg = Msg.str();
    Msg.str("");
    Msg.clear();
    Msg << "Total: " << (int) this->LvlLength * 350 + this->Width;
    LengthMsg = Msg.str();
    Msg.str("");
    Msg.clear();

    if (this->State == GAME_ACTIVE || (this->State==GAME_LOSE && this->GameEndTimer > 0)) {
        Renderer->shader.SetFloat("BgTranslate", this->BgDistance, 1);

        Renderer->DrawSprite(BGTexture, glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0, glm::vec3(1, 1, 1),
                             1);
        Renderer->shader.SetFloat("BgTranslate", 0, 1);
        Renderer->shader.SetInteger("glowSprite", this->Pressed && this->State == GAME_ACTIVE, 1);
        Renderer->shader.SetVector2f("centerCoord", glm::vec2(Renderer->Position.x + Renderer->Radius, 600 - Renderer->Position.y - Renderer->Radius), 1);
        Renderer->DrawSprite(MyTexture,
                             Renderer->Position, Renderer->Size, Renderer->Rotation, Renderer->Color, 0);
//        Renderer->shader.SetInteger("glowSprite", 0, 0);
        for (auto coinObj: this->Coins) {
            if (!coinObj->Destroyed)
                coinObj->Draw(*Renderer);
        }

        Renderer->shader.SetInteger("glowBar", 1, 1);
        for (auto zap: this->Zappers) {
            Renderer->shader.SetVector2f("bar1", zap->GetFirstpoint());
            Renderer->shader.SetVector2f("bar2", zap->GetSecondPoint());
            zap->Draw(*Renderer);
        }
        Renderer->shader.SetInteger("glowBar", 0, 1);

        this->HUD->Draw(*Renderer);
        Text->RenderText(LvlMsg, 10, 10, 1, glm::vec3(1));
        Text->RenderText(ScoreMsg, 160, 10, 1, glm::vec3(1));
        Text->RenderText(DistMsg, 310, 10, 1, glm::vec3(1));
        Text->RenderText(LengthMsg, 550, 10, 1, glm::vec3(1));
    } else if (this->State == GAME_LOSE) {
        if (this->GameEndTimer > 0){
            Renderer->shader.SetFloat("BgTranslate", this->BgDistance, 1);
            Renderer->DrawSprite(BGTexture, glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0, glm::vec3(1, 1, 1),
                                 1);
            Renderer->shader.SetFloat("BgTranslate", 0, 1);
            Renderer->DrawSprite(MyTexture,
                                 Renderer->Position, Renderer->Size, Renderer->Rotation, Renderer->Color, 0);
            for (auto coinObj: this->Coins) {
                if (!coinObj->Destroyed)
                    coinObj->Draw(*Renderer);
            }
            for (auto zap: this->Zappers) {
                zap->Draw(*Renderer);
            }
        }
        else {
            Text->RenderText("YOU LOSE", this->Width / 4, this->Height / 3, 3, glm::vec3(1, 0, 0));
            Text->RenderText(ScoreMsg, 6*this->Width /13, this->Height / 4, 1, glm::vec3(1, 0, 0));
            Text->RenderText("Press Enter to play again", this->Width / 3, 2*this->Height / 3, 1, glm::vec3(1, 0, 0));
        }
    } else if (this->State == GAME_WIN) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        Text->RenderText("YOU WIN !!", this->Width / 4, this->Height / 3, 3, glm::vec3(0, 1, 0));
        Text->RenderText(ScoreMsg, 6*this->Width / 13, this->Height / 4, 1, glm::vec3(0, 1, 0));
        Text->RenderText("Press Enter to play again", this->Width / 3, 2*this->Height / 3, 1, glm::vec3(0, 1, 0));
    }
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
    // retrieve vector between center circle and closest point AABB and check if length < = radius
    difference = closest - center;
    return glm::length(difference) < one.Radius;
}

bool Game::CheckRotatedCollision(SpriteRenderer &one, GameObject &two) {
    glm::mat4 rot = glm::mat4(1.0f);
    rot = glm::rotate(rot, glm::radians(-two.Rotation), glm::vec3(0.0f, 0.0f, 1.0f));

    // get center point circle first
    glm::vec4 center4(one.Position.x + one.Radius, one.Position.y + one.Radius, 0, 1);

    // calculate AABB info (center, half-extents)
    glm::vec2 aabb_half_extents(two.Size.x / 2.0f, two.Size.y / 2.0f);
    glm::vec4 aabb_center4(
            two.Position.x + aabb_half_extents.x,
            two.Position.y + aabb_half_extents.y,
            0, 0
    );

    center4 -= aabb_center4;
    aabb_center4 -= aabb_center4;
    center4 = rot * center4;

    glm::vec2 center, aabb_center;

    center = glm::vec2(center4.x, center4.y);
    aabb_center = glm::vec2(aabb_center4.x, aabb_center4.y);

    // get difference vector between both centers
    glm::vec2 difference = center - aabb_center;
    glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
    // add clamped value to AABB_center and we get the value of box closest to circle
    glm::vec2 closest = aabb_center + clamped;
    // retrieve vector between center circle and closest point AABB and check if length <= radius
    difference = closest - center;
    return glm::length(difference) < one.Radius;
}