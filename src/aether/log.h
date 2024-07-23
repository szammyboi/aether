#pragma once

#include <memory.h>
#include <spdlog/spdlog.h>

namespace Aether {
	class Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetAetherLogger() { return s_AetherLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_AetherLogger;
	};
}

#ifndef AETHER_RELEASE
    #define CORE_ERROR(...) ::Aether::Log::GetCoreLogger()->error(__VA_ARGS__)
    #define CORE_WARN(...)  ::Aether::Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define CORE_INFO(...)  ::Aether::Log::GetCoreLogger()->info(__VA_ARGS__)
    #define CORE_TRACE(...) ::Aether::Log::GetCoreLogger()->trace(__VA_ARGS__)

    #define AETHER_ERROR(...) ::Aether::Log::GetAetherLogger()->error(__VA_ARGS__)
    #define AETHER_WARN(...)  ::Aether::Log::GetAetherLogger()->warn(__VA_ARGS__)
    #define AETHER_INFO(...)  ::Aether::Log::GetAetherLogger()->info(__VA_ARGS__)
    #define AETHER_TRACE(...) ::Aether::Log::GetAetherLogger()->trace(__VA_ARGS__)
#else
	#define CORE_ERROR(...)
	#define CORE_WARN(...)
	#define CORE_INFO(...)
	#define CORE_TRACE(...)
	#define AETHER_ERROR(...)
	#define AETHER_WARN(...)
	#define AETHER_INFO(...)
	#define AETHER_TRACE(...)
#endif
