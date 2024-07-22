#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_VulkanLogger;

void Log::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_CoreLogger = spdlog::stdout_color_mt("APP");
    s_CoreLogger->set_level(spdlog::level::trace);

    s_VulkanLogger = spdlog::stdout_color_mt("AETHER");
    s_VulkanLogger->set_level(spdlog::level::trace);
}
