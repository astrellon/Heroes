#pragma once

#include "Stat.h"
#include "Errors.h"
#include "Modifier.h"
#include "ModifierStack.h"

#include "IModifiable.h"
#include "INamedObject.h"

#include <iostream>
#include <string>

using namespace std;

typedef float StatType;
typedef map<string, StatType> StatPair;



class StatManagement : public IModifiable
{
public:
	StatManagement() {};
	~StatManagement() {};

	StatType getStat(Stat *stat);
	StatType getStat(string shortName);

	StatType getBaseStat(Stat *stat);
	StatType getBaseStat(string shortName);

	StatType changeStat(Stat *stat, StatType amount);
	StatType changeStat(string shortName, StatType amount);

	void setStat(string shortName, StatType value);
	void setStat(Stat *stat, StatType value);

	virtual bool addModifier(string statShortName, Modifier *modifier);
	virtual bool addModifier(INamedObject *stat, Modifier *modifier);
	virtual bool removeModifier(string statShortName, Modifier *modifier);
	virtual bool removeModifier(INamedObject *stat, Modifier *modifier);
	virtual float modifyValue(string statShortName, float value);
	virtual float modifyValue(INamedObject *stat, float value);

	StatPair *getStats();
	int setStats(StatPair *stats, bool merge = false);
	
	void addAllStats();

	void displayStats();
	static void displayStatPair(StatPair *pair);

protected:
	StatPair m_stats;
};
