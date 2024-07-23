#include "window.h"
#include "GLFW/glfw3.h"
#include "error.h"
#include "log.h"

namespace Aether {
	Window::Window(const WindowSpecification& spec)
		: m_Specification(spec)
	{
		Initialize();
		AETHER_INFO("Window Created!");
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
		AETHER_INFO("Window Destroyed!");
	}


	void Window::FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::Initialize()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWmonitor* monitor = glfwGetPrimaryMonitor();

		if (m_Specification.fullscreen)
		{
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			glfwWindowHint(GLFW_RED_BITS, mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

			m_Specification.width = mode->width;
			m_Specification.height = mode->height;
		}

		m_Window = glfwCreateWindow(m_Specification.width, m_Specification.height, m_Specification.name.c_str(), m_Specification.fullscreen ? monitor : nullptr, nullptr);

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

		glViewport(0, 0, m_Specification.width, m_Specification.height);

		glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
	}
}
