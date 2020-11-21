#pragma once

#include <GLFW/glfw3.h>

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"

namespace Axolotl {

	class AX_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();
		private:
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
	};

	AX_API Application* CreateApplication();

}