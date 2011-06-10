#include "Stat.h"

Stat::Stat(string fullName, string shortName)
{
	m_full_name = fullName;
	m_short_name = shortName;
}

bool Stat::addStat(Stat *stat)
{
	if(s_stats.find(stat->getShortName()) == s_stats.end())
	{
		s_stats[stat->getShortName()] = stat;
		return true;
	}
	return false;
}
Stat *Stat::getStat(string shortName)
{
	map<string, Stat *>::iterator iter = s_stats.find(shortName);
	if(iter == s_stats.end())
	{
		return NULL;
	}
	return iter->second;
}

void Stat::addDefaultStats()
{
	if(s_defaults_added)
	{
		return;
	}

	ATTACK = new Stat("Attack", "atk");
	addStat(ATTACK);
	DEFENCE = new Stat("Defence", "dfn");
	addStat(DEFENCE);
	SPELLPOWER = new Stat("Spellpower", "spwr");
	addStat(SPELLPOWER);
	KNOWLEDGE = new Stat("Knowledge", "kwlg");
	addStat(KNOWLEDGE);

	s_defaults_added = true;
}

StatDefPair Stat::s_stats;
bool Stat::s_defaults_added = false;

Stat *Stat::ATTACK;
Stat *Stat::DEFENCE;
Stat *Stat::SPELLPOWER;
Stat *Stat::KNOWLEDGE;