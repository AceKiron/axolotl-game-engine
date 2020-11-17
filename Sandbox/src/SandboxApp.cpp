#include <Axolotl.h>

class Sandbox : public Axolotl::Application {
	public:
		Sandbox() {
		}
		~Sandbox() {
		}
};

Axolotl::Application* Axolotl::CreateApplication() {
	return new Sandbox();
}