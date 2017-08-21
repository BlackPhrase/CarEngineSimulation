#include <cstdlib>
#include "Engine.hpp"
#include "Gearbox.hpp"
#include "EngineController.hpp"

int main(int argc, char **argv)
{
	cEngine Engine("KA24", 4, 134);
	
	tGearboxGearVec vGearboxGears;
	
	vGearboxGears.push_back(std::make_unique<sGearboxGear>(0.0f)); // N
	vGearboxGears.push_back(std::make_unique<sGearboxGear>(1.0f)); // 1
	vGearboxGears.push_back(std::make_unique<sGearboxGear>(1.0f)); // 2
	vGearboxGears.push_back(std::make_unique<sGearboxGear>(1.0f)); // 3
	vGearboxGears.push_back(std::make_unique<sGearboxGear>(1.0f)); // 4
	vGearboxGears.push_back(std::make_unique<sGearboxGear>(-1.0f)); // R
	
	cGearbox Gearbox(vGearboxGears);
	
	Engine.SetGearbox(&Gearbox);
	
	cEngineController Controller;
	
	Controller.StartEngine(&Engine);
	
	while(Engine.IsRunning())
	{
		Controller.RevEngine(&Engine, 1.0f);
	};
	
	Controller.StopEngine(&Engine);
	
	return EXIT_SUCCESS;
};