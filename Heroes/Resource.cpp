#include "Resource.h"

Resource::Resource(string fullName, string shortName)
{
	m_full_name = fullName;
	m_short_name = shortName;
}

bool Resource::addResource(Resource *resource)
{
	if(s_resources.find(resource->getShortName()) == s_resources.end())
	{
		s_resources[resource->getShortName()] = resource;
		return true;
	}
	return false;
}
Resource *Resource::getResource(string shortName)
{
	map<string, Resource *>::iterator iter = s_resources.find(shortName);
	if(iter == s_resources.end())
	{
		return NULL;
	}
	return iter->second;
}

void Resource::addDefaultResources()
{
	if(s_defaults_added)
	{
		return;
	}

	GOLD = new Resource("Gold", "gld");
	addResource(GOLD);
	WOOD = new Resource("Wood", "wd");
	addResource(WOOD);
	ORE = new Resource("Ore", "ore");
	addResource(ORE);
	CRYSTAL = new Resource("Crystal", "cry");
	addResource(CRYSTAL);
	MERCURY = new Resource("Mercury", "mer");
	addResource(MERCURY);
	SULFUR = new Resource("Sulfur", "sul");
	addResource(SULFUR);

	s_defaults_added = true;
}

ResourceDefPair Resource::s_resources;
bool Resource::s_defaults_added = false;

Resource *Resource::GOLD;
Resource *Resource::WOOD;
Resource *Resource::ORE;
Resource *Resource::CRYSTAL;
Resource *Resource::MERCURY;
Resource *Resource::SULFUR;