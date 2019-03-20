#version 450

layout (location = 0) in vec4 a_Position;
layout (location = 1) in vec4 a_Color;

uniform float u_Time;

void main()
{
	float x = (cos(u_Time) + a_Position.x) * 0.5f;
	float y = (sin(u_Time) + a_Position.y) * 0.5f;
	gl_Position = vec4(x, y, a_Position.z, 1);
}
