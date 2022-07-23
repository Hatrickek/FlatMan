#include <FlatEngine.h>
#include <core/EntryPoint.h>
#include "gamelayer.h"

namespace FlatEngine {
	class FlatMan : public Application {
	public:
		FlatMan (const AppSpec& spec) : Application(spec) {
			PushLayer(new GameLayer());
		}
	};
	Application* CreateApplication(ApplicationCommandLineArgs args) {
		AppSpec spec;
		spec.Name = "FlatMan";
		spec.CommandLineArgs = args;
		return new FlatMan(spec);
	}
}