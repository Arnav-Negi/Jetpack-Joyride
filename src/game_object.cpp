//
// Created by arnav on 28/1/23.
//
#include "game_object.h"


GameObject::GameObject()
        : Position(0.0f, 0.0f), Size(1.0f, 1.0f), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false),
          Destroyed(false), ZapperRigid(true) {}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity, float isBg)
        : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false),
          Destroyed(false), isBg(isBg), ZapperRigid(true) {}

void GameObject::Draw(SpriteRenderer &renderer) {
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color, this->isBg);
}

BallObject::BallObject()
        : GameObject(), Radius(12.5f), Stuck(true) {}

BallObject::BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite)
        : GameObject(pos, glm::vec2(radius * 2.0f, radius * 2.0f), sprite, glm::vec3(1.0f), velocity), Radius(radius),
          Stuck(true) {}

glm::vec2 GameObject::Move(float dt, unsigned int window_height, float Vel) {
    // move the ball
    this->Position.x += Vel*dt;

    if (!this->ZapperRigid) this->Rotation += 10 * dt;

    return this->Position;
}

// resets the ball to initial Stuck Position (if ball is outside window bounds)
void BallObject::Reset(glm::vec2 position, glm::vec2 velocity) {
    this->Position = position;
    this->Velocity = velocity;
    this->Stuck = true;
}

glm::vec2 GameObject::GetFirstpoint() {
    glm::vec2 center = glm::vec2(this->Position.x + this->Size.x/2, this->Position.y + this->Size.y/2);
    glm::vec2 FirstPoint = glm::vec2(this->Position.x + this->Size.x/2, this->Position.y);
    FirstPoint -= center;
    glm::vec4 FpointExt = glm::vec4(FirstPoint.x, FirstPoint.y, 0, 1);
    FpointExt = glm::rotate(glm::mat4(1.0f), glm::radians(this->Rotation), glm::vec3(0,0,1))*FpointExt;
    FirstPoint = glm::vec2(FpointExt.x, FpointExt.y) + center;

    return glm::vec2(FirstPoint.x, 600 - FirstPoint.y);
}

glm::vec2 GameObject::GetSecondPoint() {
    glm::vec2 center = glm::vec2(this->Position.x + this->Size.x/2, this->Position.y + this->Size.y/2);
    glm::vec2 SecondPoint = glm::vec2(this->Position.x + this->Size.x/2, this->Position.y + this->Size.y);
    SecondPoint -= center;
    glm::vec4 SpointExt = glm::vec4(SecondPoint.x, SecondPoint.y, 0, 1);
    SpointExt = glm::rotate(glm::mat4(1.0f), glm::radians(this->Rotation), glm::vec3(0,0,1))*SpointExt;
    SecondPoint = glm::vec2(SpointExt.x, SpointExt.y) + center;

    return glm::vec2(SecondPoint.x, 600 - SecondPoint.y);
}