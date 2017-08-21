#include "EngineAlternator.hpp"
#include "Engine.hpp"

cEngineAlternator::cEngineAlternator(cEngine *apEngine) : mpEngine(apEngine){}
cEngineAlternator::~cEngineAlternator() = default;

void cEngine::Update()
{
	if(!mbActive || !mpEngine)
		return;
};