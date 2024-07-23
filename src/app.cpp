#include "app.h"
#include "aether/log.h"
#include "aether/window.h"
#include "aether/shader.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

App::App()
{
	Aether::Log::Init();
	Initialize();
}

void App::Initialize()
{
	Aether::WindowSpecification specification;
	specification.width = 900;
	specification.height = 500;
	specification.name = "Aether";
	// specification.fullscreen = true;
	m_Window = std::make_shared<Aether::Window>(specification);
}


// WARN: Temporary

const float vertices[] = {
	-0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

void App::Run()
{
	Aether::Shader shader("shaders/triangle.vert", "shaders/triangle.frag");

	unsigned int VBO;
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	shader.Use();
	while (m_Window->isOpen())
	{
		glfwSwapBuffers(m_Window->GetNative());
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
	}
}
