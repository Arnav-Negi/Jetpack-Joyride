#include "game.h"

SpriteRenderer *Renderer;

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
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/awesomeface.png", true, "sprite");
    ResourceManager::LoadTexture("/home/arnav/courses/4/cg/ass1/src/textures/BG.png", true, "background");

    this->SpriteAcc = -300;
    Renderer->Position = glm::vec2(100, this->Height - Renderer->Size.y);
    Renderer->Velocity = glm::vec2(0, 0);
    Renderer->Rotation = 0;
    Renderer->Size = glm::vec2(100, 100);
    Renderer->Color = glm::vec3(1, 1, 1);
    this->BgDistance = 0;
    this->BgVelocity = 0.02;
}

void Game::Update(float dt) {
    float NetAcc = this->SpriteAcc + this->Keys[GLFW_KEY_SPACE] * 500;
    Renderer->Velocity.y -= NetAcc * dt;
    if (Renderer->Velocity.y > 250) Renderer->Velocity.y = 250;
    Renderer->Position += Renderer->Velocity * dt;
    if (Renderer->Position.y > this->Height - Renderer->Size.y) {
        Renderer->Position.y = this->Height - Renderer->Size.y;
        Renderer->Velocity = glm::vec2(0, 0);
    }
    if (Renderer->Position.y < 0) {
        Renderer->Position.y = 0;
        Renderer->Velocity = glm::vec2(0, 0);
    }
    Renderer->Rotation += 10 * dt;
    this->BgDistance += this->BgVelocity*dt;
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
}
