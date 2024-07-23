// TODO: Make a decision on namespace scheme
// TODO: Choose a style format for function names and classes

#include "app.h"
#include "aether/error.h"
#include "aether/log.h"

int main()
{
	try
	{
		App app;
		app.Run();
	}
	catch (Aether::CoreException core_exception)
	{
		CORE_ERROR(core_exception.what());
	}
	catch (Aether::EngineException engine_exception)
	{
		AETHER_ERROR(engine_exception.what());
	}
}
