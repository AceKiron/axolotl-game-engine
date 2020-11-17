#pragma once

#ifdef AX_PLATFORM_WINDOWS
	extern Axolotl::Application* Axolotl::CreateApplication();

	int main(int argc, char** argv) {
		auto app = Axolotl::CreateApplication();
		app->Run();
		delete app;
	}
#endif