#include "app.h"
#include "log.h"
#include "window.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

App::App()
{
	Log::Init();
	Initialize();
}

void App::Initialize()
{
	m_Window = std::make_shared<Window>();
}

void App::Run()
{
	while (m_Window->isOpen())
	{
		glfwPollEvents();
	}
}
