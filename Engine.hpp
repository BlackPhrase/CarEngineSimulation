#pragma once

#include <string>

using string = std::string;

class cGearbox;

class cEngine final
{
public:
	cEngine(const string &asName, int anPistonCount, float anHorsePower);
	~cEngine();
	
	void Update();
	
	void Reset();
	
	bool Start();
	void Stop();
	
	const string &GetName() const {return msName;}
	
	int GetPistonCount() const {return mnPistonCount;}
	
	float GetMaxHorsePower() const {return mfHorsePower;}
	float GetCurrentHorsePower() const {return mfTorque * mnRPM / 5252;}
	
	void SetThrottle(float afThrottle);
	float GetThrottle() const {return mfThrottle;}
	
	float GetTorque() const {return mfTorque;}
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
	
	float mfHorsePower{0.0f};
	float mfThrottle{0.0f};
	float mfTorque{0.0f};
	
	int mnRPM{0};
	int mnPistonCount{0};
	
	bool mbRunning{false};
};