#include "app.h"
#include "log.h"
#include "window.h"
#include "shader.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

App::App()
{
	Log::Init();
	Initialize();
}

void App::Initialize()
{
	WindowSpecification specification;
	specification.width = 900;
	specification.height = 500;
	specification.name = "Aether";

	m_Window = std::make_shared<Window>(specification);
}


// WARN: Temporary

const float vertices[] = {
	-0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

void App::Run()
{
	Shader shader("shaders/triangle.vert", "shaders/triangle.frag");
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	while (m_Window->isOpen())
	{
		glfwSwapBuffers(m_Window->GetNative());
		glfwPollEvents();
	}
}
