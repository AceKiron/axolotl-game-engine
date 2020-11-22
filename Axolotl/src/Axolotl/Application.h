#pragma once

#include <GLFW/glfw3.h>

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"

// This might be moved to Core.h or Events/Event.h later
#define BIND_EVENT_FUNCTION(x) std::bind(&x, this, std::placeholders::_1)

namespace Axolotl {

	class AX_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();

			void OnEvent(Event& e);
		private:
			bool OnWindowClose(WindowCloseEvent& e);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
	};

	AX_API Application* CreateApplication();

}