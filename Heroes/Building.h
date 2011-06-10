#pragma once

#include "ResourceManagement.h"
#include <string>

using namespace std;

class Building;

typedef map<string, Building *> BuildingPair;

class Building
{
public:
	Building(string buildingName, string buildingId);
	~Building() {};

	inline string getBuildingId() { return m_building_id; }
	inline string getBuildingName() { return m_building_name; }

	void setBuildingResourceReq(string resourceId, ResourceType amount);

	ResourceType getBuildingResourceReq(string resourceId);

	ResourcePair *getAllBuildingResourceReqs();

	static void addBuilding(Building *building);
	static Building *getBuilding(string buildingId);
	static void addDefaultBuildings();

protected:

	string m_building_id;
	string m_building_name;

	ResourcePair m_resource_requirements;
	
	static BuildingPair s_all_buildings;
};
