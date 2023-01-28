#version 330 core
layout (location = 0) in vec4 vertex;
out vec2 TexCoords;
uniform float BgTranslate;
uniform mat4 model;
uniform mat4 projection;
void main()
{
    TexCoords = vec2(vertex.z + BgTranslate, vertex.w);
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
};
