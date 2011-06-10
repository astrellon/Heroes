#include "Town.h"

Town::Town()
{
	init();
}

Town::Town(string name)
{
	init();
	setName(name);
}

Town::Town(string name, Player *owner)
{
	init();
	setName(name);
	if(owner != NULL)
	{
		owner->setTownOwnership(this, true);
	}
}

void Town::init()
{
	setName("No name");
	m_owner = NULL;
}

void Town::setOwner(Player *player)
{
	m_owner = player;
}

Player *Town::getOwner()
{
	return m_owner;
}

void Town::setBuildingAvailability(string buildingId, bool availability)
{
	BuildingFlagPair::iterator iter = m_available_buildings.find(buildingId);
	bool found = iter != m_available_buildings.end();
	if(!found && availability)
	{
		m_available_buildings.insert(buildingId);
	}
	else if(found && !availability)
	{
		m_available_buildings.erase(iter);
	}
	
}

int Town::build(string buildingId)
{
	Building *building = Building::getBuilding(buildingId);
	if(building == NULL)
	{
		return BUILDING_NOT_FOUND;
	}

	BuildingFlagPair::iterator found = m_available_buildings.find(buildingId);
	if(found == m_available_buildings.end())
	{
		return BUILDING_NOT_AVAILABLE;
	}

	found = m_built_buildings.find(buildingId);
	if(found != m_built_buildings.end())
	{
		return BUILDING_ALREADY_BUILT;
	}

	bool doBuild = false;

	// If the town currently isn't owned by anyone then we'll assume
	// that the building can be built without needing any resources.
	if(m_owner == NULL)
	{
		doBuild = true;
	}

	ResourcePair afterBuy = m_owner->getResources()->buyingResults(building->getAllBuildingResourceReqs());
	if(ResourceManagement::canAfford(&afterBuy))
	{
		m_owner->getResources()->setResources(&afterBuy);
		doBuild = true;
	}
	else
	{
		return NOT_ENOUGH_RESOURCES;
	}

	if(doBuild)
	{
		m_built_buildings.insert(buildingId);
		return SUCCESS;
	}
	return UNKNOWN_ERROR;
}

void Town::displayAvailableBuildings()
{
	if(m_available_buildings.empty())
	{
		cout << "None" << endl;
		return;
	}

	BuildingFlagPair::iterator iter = m_available_buildings.begin();
	BuildingFlagPair::iterator end = m_available_buildings.end();
		
	while(iter != end)
	{
		Building *building = Building::getBuilding(*iter);
		if(building != NULL)
		{
			cout << building->getBuildingName() << endl;
		}
		iter++;
	}
}

void Town::displayBuiltBuildings()
{
	if(m_built_buildings.empty())
	{
		cout << "None" << endl;
		return;
	}

	BuildingFlagPair::iterator iter = m_built_buildings.begin();
	BuildingFlagPair::iterator end = m_built_buildings.end();
	while(iter != end)
	{
		Building *building = Building::getBuilding(*iter);
		if(building != NULL)
		{
			cout << building->getBuildingName() << endl;
		}
		iter++;
	}
}