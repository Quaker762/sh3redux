#version 450 core

in vec2 uv;
out vec3 color;

uniform sampler2D texSampler;
uniform vec4 tCol;
void main()
{
  //color = texture(texSampler, uv).rgb;
	color = tCol;
}
