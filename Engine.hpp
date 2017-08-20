#pragma once

#include <string>

using string = std::string;

class cGearbox;

class cEngine final
{
public:
	cEngine(const string &asName, int anPistonCount, int anBaseHP);
	~cEngine();
	
	void Reset();
	
	bool Start();
	void Stop();
	
	bool Rev(float afThrottle);
	
	const string &GetName() const {return msName;}
	
	int GetPistonCount() const {return mnPistonCount;}
	
	int GetHP() const {return mnHP;}
	int GetBaseHP() const {return mnBaseHP;}
	
	int GetRPM() const {return mnRPM;}
	
	//void AddComponent(iEngineComponent *apComponent);
	
	//template<typename T>
	//T *GetComponent() const;
	
	void SetGearbox(cGearbox *apGearbox){mpGearbox = apGearbox;}
	cGearbox *GetGearbox() const {return mpGearbox;}
	
	bool IsRunning() const {return mbRunning;}
private:
	string msName{""};
	
	cGearbox *mpGearbox{nullptr};
	
	int mnPistonCount{0};
	
	int mnHP{0};
	int mnBaseHP{0};
	
	int mnRevs{0};
	int mnRPM{0};
	
	bool mbRunning{false};
};