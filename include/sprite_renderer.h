//
// Created by arnav on 28/1/23.
//

#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "shader.h"


class SpriteRenderer
{
public:
    glm::vec2   Position, Size, Velocity;
    glm::vec3   Color;
    float       Radius;
    float       Rotation;
    // Constructor (inits shaders/shapes)
    SpriteRenderer(Shader &shader);

    // Destructor
    ~SpriteRenderer();

    // Renders a defined quad textured with given sprite
    void DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f), float isBg = 0.0f);

// Render state
Shader       shader;
private:
    unsigned int quadVAO;
    // Initializes and configures the quad's buffer and vertex attributes
    void initRenderData();
};

#endif //APP_SPRITE_RENDERER_H
