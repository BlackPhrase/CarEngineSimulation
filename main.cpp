#include <cstdlib>
#include "Engine.hpp"
#include "Gearbox.hpp"
#include "EngineController.hpp"

int main(int argc, char **argv)
{
	cEngine Engine("KA24", 4, 134);
	cGearbox Gearbox;
	cEngineController Controller;
	
	Engine.SetGearbox(&Gearbox);
	
	Controller.SetEngine(&Engine);
	
	Controller.StartEngine();
	
	while(Engine.IsRunning())
	{
		Controller.RevEngine(1.0f);
	};
	
	Controller.StopEngine();
	
	return EXIT_SUCCESS;
};