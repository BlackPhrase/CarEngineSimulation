#pragma once

#include <string>

using string = std::string;

class iEngineComponent
{
public:
	enum class Type : int
	{
		Invalid = -1,
		Gearbox,
		Clutch,
	};
	
	iEngineComponent(const string &asName, Type aeType)
		: msName(asName), meType(aeType){}
	virtual ~iEngineComponent() = default;
	
	virtual void Update(){}
	
	const string &GetName() const {return msName;}
	
	Type GetType() const {return meType;}
private:
	string msName{""};
	Type meType;
};