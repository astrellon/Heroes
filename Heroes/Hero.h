#pragma once

#include <string>
#include "StatManagement.h"

using namespace std;

class Player;

class Hero
{
public:
	Hero();
	Hero(string name);
	Hero(string name, Player *owner);
	~Hero() {}

	inline void setName(string name) { m_name = name; }
	inline string getName() { return m_name; }

	inline StatManagement *getStats() { return &m_stats; }

	Player *getOwner();

	friend class Player;

	inline int getExperience() { return m_experience; }
	int getExperienceToNextLevel();
	void addExperience(int experience);
	inline int getLevel() { return m_level; }
	inline int getMaxLevel() { return m_max_level; }
	inline void setMaxLevel(int level) { m_max_level = level; }
	inline bool isAtMaxLevel() { return (m_level >= m_max_level && m_max_level > 0); }

	int getExperienceForLevel(int level);

	void displayInfo();

protected:

	void init();

	void levelUp();

	void setOwner(Player *player);

	Player *m_owner;
	string m_name;
	StatManagement m_stats;

	int m_experience;
	int m_level;
	int m_max_level;
};

#include "Player.h"
