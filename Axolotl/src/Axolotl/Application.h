#pragma once

#include "Core.h"

namespace Axolotl {

	class AX_API Application {
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	AX_API Application* CreateApplication();

}