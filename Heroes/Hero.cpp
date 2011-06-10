#include "Hero.h"

Hero::Hero()
{
	init();
}

Hero::Hero(string name)
{
	init();
	setName(name);
}

Hero::Hero(string name, Player *owner)
{
	init();
	setName(name);
	if(owner != NULL)
	{
		owner->setHeroOwnership(this, true);
	}
}

void Hero::init()
{
	m_owner = NULL;
	setName("No name");
	m_stats.addAllStats();
	m_experience = 0;
	m_max_level = -1;
	m_level = 0;
	levelUp();
}

void Hero::setOwner(Player *player)
{
	m_owner = player;
}

Player *Hero::getOwner()
{
	return m_owner;
}

void Hero::levelUp()
{
	if(m_level + 1 > m_max_level && m_max_level > 0)
	{
		return;
	}

	m_level++;
	cout << getName() << " is now level " << m_level << endl;
	if(isAtMaxLevel())
	{
		cout << getName() << " has reached level cap." << endl;
	}
}

void Hero::addExperience(int experience)
{
	cout << getName() << " gained " << experience << " XP" << endl;
	m_experience += experience;
	int nextLevel = getExperienceForLevel(m_level + 1);
	while(m_experience >= nextLevel && !isAtMaxLevel())
	{
		levelUp();
		nextLevel = getExperienceForLevel(m_level + 1);
	}
}

int Hero::getExperienceToNextLevel()
{
	int nextLevel = getExperienceForLevel(m_level + 1);
	return nextLevel - m_experience;
}

int Hero::getExperienceForLevel(int level)
{
	int l = level - 1;
	if (l < 0)
		l = 0;
	return l * l * 1000;
}

void Hero::displayInfo()
{
	cout << "Name: " << getName() << endl;
	cout << "Level: " << getLevel() << endl;

	cout << "Exp: " << getExperience();
	if(!isAtMaxLevel())
	{
		cout << "/" << getExperienceForLevel(getLevel() + 1);
	}
	cout << endl;
	
	StatPair *stats = getStats()->getStats();
	StatPair::iterator iter = stats->begin();
	StatPair::iterator end = stats->end();
	cout << "Stats:" << endl;
	while(iter != end)
	{
		Stat *stat = Stat::getStat(iter->first);
		float modifiedValue = getStats()->getStat(stat);
		cout << stat->getFullName() << ": " << modifiedValue << "/" << iter->second << endl;
		iter++;
	}
}