#include "app.h"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

App::App()
{

}

void App::Initialize()
{
	InitializeOpenGL();	
}

// TODO: ERROR HANDLING
void App::InitializeOpenGL()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int version = gladLoadGL(glfwGetProcAddress);
	if (version == 0)
	{
		// return -1;
	}
}


