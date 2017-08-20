#pragma once

class cGearbox final
{
public:
	cGearbox(int anGears);
	~cGearbox();
	
	void SetGear(int anGear);
	int GetCurrentGear() const {return mnCurrentGear;}
	
	int GetMaxGears() const {return mnGears;}
private:
	int mnGears{0};
	int mnCurrentGear{0};
};