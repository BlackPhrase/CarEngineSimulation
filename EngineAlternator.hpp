#pragma once

class cEngine;

class cEngineAlternator final
{
public:
	cEngineAlternator(cEngine *apEngine);
	~cEngineAlternator();
	
	void Update();
	
	void SetActive(bool abActive){mbActive = abActive;}
	bool IsActive() const {return mbActive;}
	
	void SetEngine(cEngine *apEngine){mpEngine = apEngine;}
private:
	cEngine *mpEngine{nullptr};
	
	bool mbActive{false};
};