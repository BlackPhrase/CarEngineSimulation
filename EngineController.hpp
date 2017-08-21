#pragma once

class cEngine;

class cEngineController final
{
public:
	cEngineController(/*cEngine *apEngine*/);
	~cEngineController();
	
	//void SetEngine(cEngine *apEngine){mpEngine = apEngine;}
	//cEngine *GetEngine() const {return mpEngine;}
	
	void StartEngine(cEngine *apEngine);
	void StopEngine(cEngine *apEngine);
	
	void RevEngine(cEngine *apEngine, float afThrottle);
	
	void SetGear(cEngine *apEngine, int anGear);
private:
	//cEngine *mpEngine{nullptr};
};