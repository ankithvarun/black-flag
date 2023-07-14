#version 330 core
out vec4 FragColor;

uniform vec4 Color;
uniform float UseTexture;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{    
    if(int(UseTexture) == 0)
        FragColor = Color;
    else
        FragColor = texture(texture_diffuse1, TexCoords);
}