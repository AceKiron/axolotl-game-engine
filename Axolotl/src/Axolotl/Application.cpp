#include "axpch.h"
#include "Application.h"

namespace Axolotl {

	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AX_LOG_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AX_LOG_TRACE(e);
		}

		while (true);
	}

}