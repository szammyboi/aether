#include "window.h"
#include "GLFW/glfw3.h"
#include "log.h"
#include "error.h"

Window::Window()
{
	Initialize();
}

void Window::Initialize()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(800, 600, "Aether", nullptr, nullptr);

	if (m_Window == nullptr)
	{
		throw Aether::EngineException("Could Not Create OpenGL Window!");
	}

	glfwMakeContextCurrent(m_Window);

	int version = gladLoadGL(glfwGetProcAddress);
	if (version == 0)
	{
		throw Aether::EngineException("Could Not Load GLFW Functions!");
	}
}

