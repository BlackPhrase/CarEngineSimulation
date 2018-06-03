#pragma once

#include <memory>
#include <vector>

#include "EngineComponent.hpp"

struct sGearboxGear
{
	sGearboxGear(float afRatio) : fRatio(afRatio){}

	float fRatio{0.0f};
};

using tGearboxGearVec = std::vector<std::unique_ptr<sGearboxGear>>;

class cGearbox final : public iEngineComponent
{
public:
	cGearbox(tGearboxGearVec &avGears);
	~cGearbox();
	
	/// Apply the current gear ratio to provided torque and return it
	float ProvideTorque(float afTorque){return afTorque * mvGears[mnCurrentGear].fRatio;}
	
	///
	void SetGear(int anGear);
	
	///
	const sGearboxGear &GetCurrentGear() const {return mvGears[mnCurrentGear];}
	
	///
	int GetGearCount() const {return mvGears.size();}
private:
	tGearboxGearVec mvGears;
	
	int mnCurrentGear{0};
};