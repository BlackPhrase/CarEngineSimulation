#include "Engine.hpp"
#include "Gearbox.hpp"

cEngine::cEngine(const string &asName, int anPistonCount, int anHorsePower)
	: msName(asName), mnPistonCount(anPistonCount), mnHorsePower(anHorsePower){}
cEngine::~cEngine() = default;

void cEngine::Update()
{
	mnTorqueMax = mnTorque / mnRPM; //LookupTorqueCurve(mnRPM);
	mnTorque = mfThrottle * mnTorqueMax;
	
	if(mnRPM >= mnIdleRPM)
		return;
};

void cEngine::Reset()
{
};

bool cEngine::Start()
{
	if(mbRunning)
		return false;
	
	mbRunning = true;
	return true;
};

void cEngine::Stop()
{
	if(mbRunning)
		mbRunning = false;
};

bool cEngine::Rev(float afThrottle)
{
	if(!mbRunning)
		return false;
	
	if(afThrottle < 0.0f)
		afThrottle = 0.0f;
	
	if(afThrottle > 1.0f)
		afThrottle = 1.0f;
	
	return true;
};