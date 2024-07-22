#pragma once

#include "window.h"
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
	std::shared_ptr<Window> m_Window;
};
