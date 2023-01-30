//
// Created by arnav on 28/1/23.
//
#include "game_object.h"


GameObject::GameObject()
        : Position(0.0f, 0.0f), Size(1.0f, 1.0f), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false),
          Destroyed(false) {}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity, float isBg)
        : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false),
          Destroyed(false), isBg(isBg) {}

void GameObject::Draw(SpriteRenderer &renderer) {
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color, this->isBg);
}

BallObject::BallObject()
        : GameObject(), Radius(12.5f), Stuck(true) {}

BallObject::BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite)
        : GameObject(pos, glm::vec2(radius * 2.0f, radius * 2.0f), sprite, glm::vec3(1.0f), velocity), Radius(radius),
          Stuck(true) {}

glm::vec2 GameObject::Move(float dt, unsigned int window_height) {
    // move the ball
    this->Position += this->Velocity*dt;

    return this->Position;
}

// resets the ball to initial Stuck Position (if ball is outside window bounds)
void BallObject::Reset(glm::vec2 position, glm::vec2 velocity) {
    this->Position = position;
    this->Velocity = velocity;
    this->Stuck = true;
}