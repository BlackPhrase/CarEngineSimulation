#pragma once

#include <memory>
#include <vector>

struct sGearboxGear
{
	sGearboxGear(float afRatio) : fRatio(afRatio){}

	float fRatio{0.0f};
};

using tGearboxGearVec = std::vector<std::unique_ptr<sGearboxGear>>;

class cGearbox final
{
public:
	cGearbox(tGearboxGearVec &avGears);
	~cGearbox();
	
	//float ApplyRatio(float afTorque){return afTorque * mvGears[mnCurrentGear].fRatio;}
	
	void SetGear(int anGear);
	const sGearboxGear &GetCurrentGear() const {return mvGears[mnCurrentGear];}
	
	int GetGearCount() const {return mvGears.size();}
private:
	tGearboxGearVec mvGears;
	
	int mnCurrentGear{0};
};