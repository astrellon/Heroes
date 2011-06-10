#include "StatManagement.h"

StatType StatManagement::getBaseStat(Stat *stat)
{
	return getBaseStat(stat->getShortName());
}

StatType StatManagement::getBaseStat(string shortName)
{
	return m_stats[shortName];
}

StatType StatManagement::getStat(Stat *stat)
{
	return getStat(stat->getShortName());
}

StatType StatManagement::getStat(string shortName)
{
	return modifyValue(shortName, m_stats[shortName]);
}

bool StatManagement::addModifier(string statShortName, Modifier *modifier)
{
	return m_modifiers[statShortName].addModifier(modifier);
}

bool StatManagement::addModifier(INamedObject *stat, Modifier *modifier)
{
	return addModifier(stat->getShortName(), modifier);
}

bool StatManagement::removeModifier(string statShortName, Modifier *modifier)
{
	return m_modifiers[statShortName].removeModifier(modifier);
}

bool StatManagement::removeModifier(INamedObject *stat, Modifier *modifier)
{
	return removeModifier(stat->getShortName(), modifier);
}

float StatManagement::modifyValue(string statShortName, float value)
{
	ModifierPair::iterator iter = m_modifiers.find(statShortName);
	if(iter == m_modifiers.end())
	{
		return value;
	}
	return iter->second.modifyValue(value);
}

float StatManagement::modifyValue(INamedObject *stat, float value)
{
	return modifyValue(stat->getShortName(), value);
}

StatType StatManagement::changeStat(Stat *stat, StatType amount)
{
	return changeStat(stat->getShortName(), amount);
}

StatType StatManagement::changeStat(string shortName, StatType amount)
{
	StatType value = m_stats[shortName];
	value += amount;
	m_stats[shortName] = value;
	return value;
}

void StatManagement::setStat(string shortName, StatType value)
{
	m_stats[shortName] = value;
}
void StatManagement::setStat(Stat *stat, StatType value)
{
	setStat(stat->getShortName(), value);
}

StatPair *StatManagement::getStats()
{
	return &m_stats;
}
int StatManagement::setStats(StatPair *stats, bool merge)
{
	if(!merge)
	{
		m_stats.clear();
	}

	m_stats = *stats;

	return SUCCESS;
}

void StatManagement::addAllStats()
{
	StatDefPair::iterator iter = Stat::getStatDefinitions()->begin();
	StatDefPair::iterator end = Stat::getStatDefinitions()->end();
	while(iter != end)
	{
		setStat(iter->first, 0);
		iter++;
	}
}

void StatManagement::displayStats()
{
	displayStatPair(&m_stats);
}

void StatManagement::displayStatPair(StatPair *pair)
{
	StatPair::iterator iter = pair->begin();
	cout << "Stats:" << endl;
	bool empty = true;
	while(iter != pair->end())
	{
		empty = false;
		cout << Stat::getStat(iter->first)->getFullName() << " = " << iter->second << endl;
		iter++;
	}
	if(empty)
	{
		cout << "None" << endl;
	}
}