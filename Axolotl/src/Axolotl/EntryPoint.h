#pragma once

#ifdef AX_PLATFORM_WINDOWS
	extern Axolotl::Application* Axolotl::CreateApplication();

	int main(int argc, char** argv) {
		Axolotl::Log::Init();

		AX_LOG_ENGINE_ERROR("Error engine test");
		AX_LOG_TRACE("Trace sandbox test, Var={0}, Var1={1}", 5.0f, 0);

		auto app = Axolotl::CreateApplication();
		app->Run();
		delete app;
	}
#endif