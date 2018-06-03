#pragma once

#include <vector>
#include <string>

using string = std::string;

class iEngineComponent;
using tEngineComponentVec = std::vector<iEngineComponent*>;

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
	
	void AddComponent(iEngineComponent *apComponent)
	{
		if(apComponent)
			mvComponents.push_back(apComponent);
	};
	
	template<typename T>
	T *GetComponent() const
	{
		for(auto It : mvComponents)
			if(It->GetType() == T.GetType())
				return dynamic_cast<T>(It);
		
		return nullptr;
	};
	
	void SetGearbox(cGearbox *apGearbox){mpGearbox = apGearbox;}
	cGearbox *GetGearbox() const {return mpGearbox;}
	
	bool IsRunning() const {return mbRunning;}
private:
	tEngineComponentVec mvComponents;
	
	string msName{""};
	
	cGearbox *mpGearbox{nullptr};
	
	float mfHorsePower{0.0f};
	float mfThrottle{0.0f};
	float mfTorque{0.0f};
	
	int mnRPM{0};
	int mnPistonCount{0};
	
	bool mbRunning{false};
};