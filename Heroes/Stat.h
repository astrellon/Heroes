#pragma once

#include "INamedObject.h"

#include <string>
#include <map>

using namespace std;

class Stat;

typedef map<string, Stat *> StatDefPair;

class Stat : public INamedObject
{
public:
	Stat(string fullName, string shortName);
	~Stat(){};

	inline virtual string getFullName() { return m_full_name; }
	inline virtual string getShortName() { return m_short_name; }

	static bool addStat(Stat *stat);
	static Stat *getStat(string shortName);
	static void addDefaultStats();
	
	inline static StatDefPair *getStatDefinitions()
	{
		return &s_stats;
	}

	static Stat *ATTACK;
	static Stat *DEFENCE;
	static Stat *SPELLPOWER;
	static Stat *KNOWLEDGE;

protected:
	string m_full_name;
	string m_short_name;

	static StatDefPair s_stats;
	static bool s_defaults_added;

	// Graphic
};
