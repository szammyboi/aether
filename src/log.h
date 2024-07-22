#pragma once

#include <memory.h>
#include <spdlog/spdlog.h>

class Log {
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetVulkanLogger() { return s_VulkanLogger; }
private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_VulkanLogger;
};

#ifndef AETHER_RELEASE
    #define CORE_ERROR(...) ::Log::GetCoreLogger()->error(__VA_ARGS__)
    #define CORE_WARN(...)  ::Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define CORE_INFO(...)  ::Log::GetCoreLogger()->info(__VA_ARGS__)
    #define CORE_TRACE(...) ::Log::GetCoreLogger()->trace(__VA_ARGS__)

    #define ENGINE_ERROR(...) ::Log::GetVulkanLogger()->error(__VA_ARGS__)
    #define ENGINE_WARN(...)  ::Log::GetVulkanLogger()->warn(__VA_ARGS__)
    #define ENGINE_INFO(...)  ::Log::GetVulkanLogger()->info(__VA_ARGS__)
    #define ENGINE_TRACE(...) ::Log::GetVulkanLogger()->trace(__VA_ARGS__)
#else
	#define CORE_ERROR(...)
	#define CORE_WARN(...)
	#define CORE_INFO(...)
	#define CORE_TRACE(...)
	#define ENGINE_ERROR(...)
	#define ENGINE_WARN(...)
	#define ENGINE_INFO(...)
	#define ENGINE_TRACE(...)
#endif
