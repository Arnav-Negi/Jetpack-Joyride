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
#include <iostream>
#include <sstream>

// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_LOSE,
    GAME_WIN
};

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // game state
    GameState               State;
    int                     Lvl;
    bool                    Keys[1024], Pressed;
    unsigned int            Width, Height;
    float                   SpriteAcc;
    float                   BgDistance, BgVelocity;
    float                   FgDistance;
    float                   CoinVel, CoinRad;
    float                   LvlLength;
    std::vector<BallObject *> Coins;
    unsigned  int           Score;
    std::vector<GameObject *> Zappers;
    GameObject *            HUD;

    float                   GameEndTimer;

    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    void InitLvl(int lvl);

    // Update Functions
    bool CheckCollision(BallObject &one, SpriteRenderer &two);
    bool CheckCollision(GameObject &one, SpriteRenderer &two);
    bool CheckRotatedCollision(SpriteRenderer &one, GameObject &two);
    void DoCollisions();
    void SpawnCoins();
    void SpawnZappers();
    void Die();
    void Win();

    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

float RandomF(float left, float right);
int RandomI(float left, float right);

#endif