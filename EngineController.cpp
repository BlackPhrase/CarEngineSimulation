#include "EngineController.hpp"
#include "Engine.hpp"
#include "Gearbox.hpp"

cEngineController::cEngineController(/*cEngine *apEngine*/) = default; //: mpEngine(apEngine){}
cEngineController::~cEngineController() = default;

void cEngineController::StartEngine(cEngine *apEngine)
{
	if(!apEngine)
		return;
	
	apEngine->Start();
};

void cEngineController::StopEngine(cEngine *apEngine)
{
	if(!apEngine)
		return;
	
	apEngine->Stop();
};

void cEngineController::RevEngine(cEngine *apEngine, float afThrottle, float afTime)
{
	if(!apEngine)
		return;
	
	//apEngine->Rev(afThrottle);
};

void cEngineController::SetGear(cEngine *apEngine, int anGear)
{
	if(!apEngine)
		return;

	cGearbox *pGearbox = apEngine->GetGearbox();
	
	if(pGearbox)
		pGearbox->SetGear(anGear);
};