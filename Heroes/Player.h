#pragma once

#include "ResourceManagement.h"
#include <string>
#include <iostream>

#include <set>

using namespace std;

class Town;
class Hero;

class Player
{
public:
	Player();
	~Player() {};

	inline ResourceManagement *getResources() { return &m_resources; }

	void displayResources();
	void displayTowns();
	void displayHeroes();

	void setTownOwnership(Town *town, bool ownership);
	void setHeroOwnership(Hero *hero, bool ownership);

protected:
	ResourceManagement m_resources;

	set<Town *> m_owned_towns;
	set<Hero *> m_owned_heroes;
};

#include "Town.h"
#include "Hero.h"
