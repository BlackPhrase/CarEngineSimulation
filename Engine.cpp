#include "Engine.hpp"
#include "Gearbox.hpp"

cEngine::cEngine(const string &asName, int anPistonCount, int anBaseHP)
	: msName(asName), mnPistonCount(anPistonCount), mnBaseHP(anBaseHP){}
cEngine::~cEngine() = default;

void cEngine::Reset()
{
	mnRevs = 0;
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
	
	++mnRevs;
	return true;
};