//
// Created by arnav on 28/1/23.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "sprite_renderer.h"


// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.
class GameObject
{
public:
    // object state
    glm::vec2   Position, Size, Velocity;
    glm::vec3   Color;
    float       Rotation;
    bool        IsSolid;
    bool        Destroyed;
    float       isBg;
    bool         ZapperRigid;
    // render state
    Texture2D   Sprite;
    // constructor(s)
    GameObject();
    GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f), float isBg = 0.0f);
    glm::vec2 Move(float dt, unsigned int window_width, float Vel);
    glm::vec2 GetFirstpoint();
    glm::vec2 GetSecondPoint();
    // draw sprite
    virtual void Draw(SpriteRenderer &renderer);
};

class BallObject : public GameObject
{
public:
    // ball state
    float     Radius;
    bool      Stuck;


    BallObject();
    BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite);

    void      Reset(glm::vec2 position, glm::vec2 velocity);
};

#endif