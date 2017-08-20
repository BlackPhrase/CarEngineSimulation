#pragma once

class cEngine;

class cEngineController final
{
public:
	cEngineController(cEngine *apEngine);
	~cEngineController();
	
	void SetEngine(cEngine *apEngine){mpEngine = apEngine;}
	cEngine *GetEngine() const {return mpEngine;}
	
	void StartEngine();
	void StopEngine();
	
	void RevEngine(float afThrottle);
	
	void SetGear(int anGear);
private:
	cEngine *mpEngine{nullptr};
};