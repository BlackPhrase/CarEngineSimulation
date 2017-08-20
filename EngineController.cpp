#include "EngineController.hpp"
#include "Engine.hpp"
#include "Gearbox.hpp"

cEngineController::cEngineController(cEngine *apEngine) : mpEngine(apEngine){}
cEngineController::~cEngineController() = default;

void cEngineController::StartEngine()
{
	if(!mpEngine)
		return;
	
	mpEngine->Start();
};

void cEngineController::StopEngine()
{
	if(!mpEngine)
		return;
	
	mpEngine->Stop();
};

void cEngineController::RevEngine(float afThrottle)
{
	if(!mpEngine)
		return;
	
	mpEngine->Rev(afThrottle);
};

void cEngineController::SetGear(int anGear)
{
	if(!mpEngine)
		return;

	cGearbox *pGearbox = mpEngine->GetGearbox();
	
	if(pGearbox)
		pGearbox->SetGear(anGear);
};