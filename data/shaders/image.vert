#version 450 core
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;

out vec2 uv;
uniform float tFloat;
void main()
{
  gl_Position.xyz = vertexPosition + tFloat;
  gl_Position.w = 1.0;
  uv = vertexUV;
}
