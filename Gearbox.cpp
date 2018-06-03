#include "Gearbox.hpp"

cGearbox::cGearbox(tGearboxGearVec &avGears)
	: iEngineComponent("Gearbox", iEngineComponent::Type::Gearbox), mvGears(avGears){}
cGearbox::~cGearbox() = default;

void cGearbox::SetGear(int anGear)
{
	if(anGear > mvGears.size())
		return;

	mnCurrentGear = anGear;
};