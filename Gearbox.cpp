#include "Gearbox.hpp"

cGearbox::cGearbox(int anGears) : mnGears(anGears){}
cGearbox::~cGearbox() = default;

void cGearbox::SetGear(int anGear)
{
	if(anGear > mnGears)
		return;

	mnCurrentGear = anGear;
};