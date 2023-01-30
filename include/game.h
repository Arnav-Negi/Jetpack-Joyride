#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "resource_manager.h"
#include "shader.h"
#include "sprite_renderer.h"
#include "game_object.h"
#include "text_renderer.h"
#include <vector>
#include <random>

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

const float COIN_VEL = -100, COIN_RAD = 25;

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // game state
    GameState               State;
    int                     Lvl;
    bool                    Keys[1024];
    unsigned int            Width, Height;
    float                   SpriteAcc;
    float                   BgDistance, BgVelocity;

    std::vector<BallObject *> Coins;
    unsigned  int           Score;
    std::vector<GameObject *> Zappers;

    bool                    Dead;

    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    void InitLvl(int lvl);

    // Update Functions
    bool CheckCollision(BallObject &one, SpriteRenderer &two);
    bool CheckCollision(GameObject &one, SpriteRenderer &two);
    void DoCollisions();
    void SpawnCoins();
    void SpawnZappers();
    void Die();

    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

float RandomF(float left, float right);
int RandomI(float left, float right);

#endif