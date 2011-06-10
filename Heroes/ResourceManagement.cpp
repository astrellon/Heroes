#include "ResourceManagement.h"

bool ResourceManagement::addModifier(string statShortName, Modifier *modifier)
{
	return m_modifiers[statShortName].addModifier(modifier);
}

bool ResourceManagement::addModifier(INamedObject *stat, Modifier *modifier)
{
	return addModifier(stat->getShortName(), modifier);
}

bool ResourceManagement::removeModifier(string statShortName, Modifier *modifier)
{
	return m_modifiers[statShortName].removeModifier(modifier);
}

bool ResourceManagement::removeModifier(INamedObject *stat, Modifier *modifier)
{
	return removeModifier(stat->getShortName(), modifier);
}

float ResourceManagement::modifyValue(string statShortName, float value)
{
	ModifierPair::iterator iter = m_modifiers.find(statShortName);
	if(iter == m_modifiers.end())
	{
		return value;
	}
	return iter->second.modifyValue(value);
}

float ResourceManagement::modifyValue(INamedObject *stat, float value)
{
	return modifyValue(stat->getShortName(), value);
}

ResourceType ResourceManagement::getResource(Resource *resource)
{
	return m_resources[resource->getShortName()];
}

ResourceType ResourceManagement::getResource(string shortName)
{
	return m_resources[shortName];
}

ResourceType ResourceManagement::changeResource(Resource *resource, ResourceType amount)
{
	return changeResource(resource->getShortName(), amount);
}

ResourceType ResourceManagement::changeResource(string shortName, ResourceType amount)
{
	ResourceType value = m_resources[shortName];
	value += amount;
	m_resources[shortName] = value;
	return value;
}

void ResourceManagement::setResource(string shortName, ResourceType value)
{
	m_resources[shortName] = value;
}
void ResourceManagement::setResource(Resource *resource, ResourceType value)
{
	m_resources[resource->getShortName()] = value;
}

ResourcePair * ResourceManagement::getResources()
{
	return &m_resources;
}
int ResourceManagement::setResources(ResourcePair *resources, bool merge)
{
	if(!ResourceManagement::canAfford(resources))
	{
		return NOT_ENOUGH_RESOURCES;
	}

	if(!merge)
	{
		m_resources.clear();
	}

	m_resources = *resources;

	return SUCCESS;
}

void ResourceManagement::addAllResources()
{
	ResourceDefPair::iterator iter = Resource::getResourceDefinitions()->begin();
	ResourceDefPair::iterator end = Resource::getResourceDefinitions()->end();
	while(iter != end)
	{
		setResource(iter->first, 0);
		iter++;
	}
}

ResourcePair ResourceManagement::buyingResults(ResourcePair *costs)
{
	ResourcePair results;
	ResourcePair::iterator iter = m_resources.begin();
	while(iter != m_resources.end())
	{
		results[iter->first] = iter->second;
		iter++;
	}

	iter = costs->begin();
	while(iter != costs->end())
	{
		results[iter->first] -= iter->second;
		iter++;
	}

	return results;
}

bool ResourceManagement::canAfford(ResourcePair *resources)
{
	bool result = true;
	ResourcePair::iterator iter = resources->begin();
	while(iter != resources->end())
	{
		if(iter->second < 0)
		{
			result = false;
			break;
		}
		iter++;
	}
	return result;
}

void ResourceManagement::displayResources()
{
	displayResourcePair(&m_resources);
}

void ResourceManagement::displayResourcePair(ResourcePair *pair)
{
	ResourcePair::iterator iter = pair->begin();
	bool empty = true;
	cout << "Resources:" << endl;
	while(iter != pair->end())
	{
		empty = false;
		cout << Resource::getResource(iter->first)->getFullName() << " = " << iter->second << endl;
		iter++;
	}
	if(empty)
	{
		cout << "None" << endl;
	}
}