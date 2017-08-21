#include "Gearbox.hpp"

cGearbox::cGearbox(tGearboxGearVec &avGears) : mvGears(avGears){}
cGearbox::~cGearbox() = default;

void cGearbox::SetGear(int anGear)
{
	if(anGear > mvGears.size())
		return;

	mnCurrentGear = anGear;
};