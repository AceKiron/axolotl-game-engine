#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Core.h"

namespace Axolotl {

	class AX_API Log {
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetAxolotlLogger() { return s_AxolotlLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetSandboxLogger() { return s_SandboxLogger; }
		private:
			static std::shared_ptr<spdlog::logger> s_AxolotlLogger;
			static std::shared_ptr<spdlog::logger> s_SandboxLogger;
	};

}

// Axolotl Game Engine logger
#define AX_LOG_ENGINE_TRACE(...)	::Axolotl::Log::GetAxolotlLogger()->trace(__VA_ARGS__)
#define AX_LOG_ENGINE_INFO(...)		::Axolotl::Log::GetAxolotlLogger()->info(__VA_ARGS__)
#define AX_LOG_ENGINE_WARN(...)		::Axolotl::Log::GetAxolotlLogger()->warn(__VA_ARGS__)
#define AX_LOG_ENGINE_ERROR(...)	::Axolotl::Log::GetAxolotlLogger()->error(__VA_ARGS__)
#define AX_LOG_ENGINE_FATAL(...)	::Axolotl::Log::GetAxolotlLogger()->fatal(__VA_ARGS__)

// Sandbox logger
#define AX_LOG_TRACE(...)	::Axolotl::Log::GetSandboxLogger()->trace(__VA_ARGS__)
#define AX_LOG_INFO(...)	::Axolotl::Log::GetSandboxLogger()->info(__VA_ARGS__)
#define AX_LOG_WARN(...)	::Axolotl::Log::GetSandboxLogger()->warn(__VA_ARGS__)
#define AX_LOG_ERROR(...)	::Axolotl::Log::GetSandboxLogger()->error(__VA_ARGS__)
#define AX_LOG_FATAL(...)	::Axolotl::Log::GetSandboxLogger()->fatal(__VA_ARGS__)
