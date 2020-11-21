#include "axpch.h"
#include "Log.h"

namespace Axolotl {

	std::shared_ptr<spdlog::logger> Log::s_AxolotlLogger;
	std::shared_ptr<spdlog::logger> Log::s_SandboxLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_AxolotlLogger = spdlog::stdout_color_mt("AXOLOTL");
		s_AxolotlLogger->set_level(spdlog::level::trace);

		s_SandboxLogger = spdlog::stdout_color_mt("SANDBOX");
		s_SandboxLogger->set_level(spdlog::level::trace);
	}

}