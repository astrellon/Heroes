#include "Building.h"

BuildingPair Building::s_all_buildings;

Building::Building(string buildingName, string buildingId)
{
	m_building_name = buildingName;
	m_building_id = buildingId;
}

void Building::setBuildingResourceReq(string resourceId, ResourceType amount)
{
	m_resource_requirements[resourceId] = amount;
}

ResourceType Building::getBuildingResourceReq(string resourceId)
{
	return m_resource_requirements[resourceId];
}

ResourcePair *Building::getAllBuildingResourceReqs()
{
	return &m_resource_requirements;
}

void Building::addBuilding(Building *building)
{
	if (s_all_buildings.find(building->getBuildingId()) == s_all_buildings.end())
	{
		s_all_buildings[building->getBuildingId()] = building;
	}
}

Building *Building::getBuilding(string buildingId)
{
	BuildingPair::iterator iter = s_all_buildings.find(buildingId);
	if(iter == s_all_buildings.end())
	{
		return NULL;
	}
	return iter->second;
}

void Building::addDefaultBuildings()
{
	Building *b = new Building("Village Hall", "vhall");
	b->setBuildingResourceReq("gld", 500);
	addBuilding(b);
	b = new Building("Town Hall", "thall");
	b->setBuildingResourceReq("gld", 1000);
	addBuilding(b);
	b = new Building("Marketplace", "mplace");
	b->setBuildingResourceReq("gld", 400);
	b->setBuildingResourceReq("wd", 5);
	addBuilding(b);
}