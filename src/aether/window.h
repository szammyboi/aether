#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Aether {
	struct WindowSpecification
	{
		unsigned width = 500;
		unsigned height = 500;
		std::string name = "Untitled";
		bool fullscreen = false;
	};

	class Window
	{
	public:
		Window(const WindowSpecification& spec);
		~Window();

		GLFWwindow* GetNative() { return m_Window; }
		inline bool isOpen() { return !glfwWindowShouldClose(m_Window); }
	private:
		void Initialize();
		static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	private:
		GLFWwindow* m_Window;
		WindowSpecification m_Specification;
	};
}
