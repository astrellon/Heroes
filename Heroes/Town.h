#pragma once

#include "Building.h"
#include "Errors.h"
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Player;

//typedef map<string, bool> BuildingFlagPair;
typedef set<string> BuildingFlagPair;

class Town
{
public:
	Town();
	Town(string name);
	Town(string name, Player *owner);
	~Town(){}

	inline void setName(string name) { m_name = name; }
	inline string getName() { return m_name; }

	Player *getOwner();
	
	void setBuildingAvailability(string buildingId, bool availability);
	int build(string buildingId);
	
	void displayAvailableBuildings();
	void displayBuiltBuildings();

	friend class Player;

protected:

	void setOwner(Player *player);
	void init();

	BuildingFlagPair m_available_buildings;
	BuildingFlagPair m_built_buildings;

	Player *m_owner;
	string m_name;
};

#include "Player.h"
