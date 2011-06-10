#pragma once

#include "INamedObject.h"

#include <map>
#include <string>

using namespace std;

class Resource;

typedef map<string, Resource *> ResourceDefPair;

class Resource : public INamedObject
{
public:
	Resource(string fullName, string shortName);
	~Resource(){};

	inline virtual string getFullName() { return m_full_name; }
	inline virtual string getShortName() { return m_short_name; }

	static bool addResource(Resource *resource);
	static Resource *getResource(string shortName);
	static void addDefaultResources();
	
	inline static ResourceDefPair *getResourceDefinitions()
	{
		return &s_resources;
	}

	static Resource *GOLD;
	static Resource *WOOD;
	static Resource *ORE;
	static Resource *CRYSTAL;
	static Resource *MERCURY;
	static Resource *SULFUR;

protected:
	string m_full_name;
	string m_short_name;

	static ResourceDefPair s_resources;
	static bool s_defaults_added;

	// Graphic
};
