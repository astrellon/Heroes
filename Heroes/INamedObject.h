#pragma once

#include <string>

using namespace std;

class INamedObject
{
public:
	virtual string getFullName() = 0;
	virtual string getShortName() = 0;
};
