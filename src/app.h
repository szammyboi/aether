#pragma once

#include "aether/window.h"
#include <memory>

class App
{
public:
	App();
	~App() = default;

	void Run();
private:
	void Initialize();
private:
	std::shared_ptr<Aether::Window> m_Window;
};
