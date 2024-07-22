#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window() = default;
	~Window() = default;
private:
	GLFWwindow* m_Window;
};
