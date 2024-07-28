#version 330 core
layout (location = 0) in vec3 aPos;


uniform float y_pos;
uniform float x_pos;
void main()
{
    gl_Position = vec4(aPos.x + x_pos, aPos.y + y_pos, aPos.z, 1.0);
}
