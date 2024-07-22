#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window();
	~Window() = default;

	inline bool isOpen() { return !glfwWindowShouldClose(m_Window); }
private:
	void Initialize();
private:
	GLFWwindow* m_Window;
};
