#include "Engine.hpp"
#include "Gearbox.hpp"

cEngine::cEngine(const string &asName, int anPistonCount, float afHorsePower)
	: msName(asName), mnPistonCount(anPistonCount), mfHorsePower(afHorsePower){}
cEngine::~cEngine() = default;

void cEngine::Update()
{
	mfTorqueMax = mfTorque / mnRPM; //LookupTorqueCurve(mnRPM);
	mfTorque = mfThrottle * mfTorqueMax;
	
	//if(mnRPM >= mnIdleRPM)
		//return;
	
	if(mpGearbox)
		mpGearbox->ProvideTorque(mfTorque);
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

void cEngine::SetThrottle(float afThrottle)
{
	if(afThrottle < 0.0f)
		afThrottle = 0.0f;
	
	if(afThrottle > 1.0f)
		afThrottle = 1.0f;
	
	mfThrottle = afThrottle;
};