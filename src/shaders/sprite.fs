#version 330 core
out vec4 FragColor;
in vec2 TexCoords;
uniform sampler2D image;
uniform int glowSprite, glowBar;
uniform vec2 iResolution, centerCoord;
uniform vec2 bar1, bar2;
uniform vec3 spriteColor;

void main()
{
    vec2 uv = gl_FragCoord.xy/iResolution.xy;
    uv -= centerCoord.xy/iResolution.xy;
    uv.x *= iResolution.x/iResolution.y;

    FragColor = vec4(spriteColor, 1.0);
    FragColor *= texture(image, TexCoords);

    float dist = length(uv);
    if (dist < 0.08 && dist > 0.05  && glowSprite == 1 && !(glowBar == 1)) {
        float c = smoothstep(0.15, 0.05, dist);
        FragColor *= vec4(c*5,c*5,0,1);
    }

    if (glowBar == 1) {
        float lenBar = length(bar1-bar2);
        float height = length(cross(vec3(bar1.xy, 0) - vec3(gl_FragCoord.xy, 0), vec3(bar2.xy, 0) - vec3(gl_FragCoord.xy, 0)))/lenBar;

        if (height < 10) {
            float r = smoothstep(15, 0, height);
            FragColor *= vec4(r,r,0,0.8);
        }
    }
};
