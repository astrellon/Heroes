#pragma once

#include <map>
#include <string>
#include <iostream>

using namespace std;

#include "INamedObject.h"
#include "IModifiable.h"

#include "Resource.h"
#include "Errors.h"

typedef int ResourceType;
typedef map<string, ResourceType> ResourcePair;

class ResourceManagement : public IModifiable
{
public:
	ResourceManagement() {};
	~ResourceManagement() {};

	ResourceType getResource(Resource *resource);
	ResourceType getResource(string shortName);

	ResourceType changeResource(Resource *resource, ResourceType amount);
	ResourceType changeResource(string shortName, ResourceType amount);
	void setResource(string shortName, ResourceType value);
	void setResource(Resource *resource, ResourceType value);
	
	virtual bool addModifier(string resShortName, Modifier *modifier);
	virtual bool addModifier(INamedObject *res, Modifier *modifier);
	virtual bool removeModifier(string resShortName, Modifier *modifier);
	virtual bool removeModifier(INamedObject *res, Modifier *modifier);
	virtual float modifyValue(string resShortName, float value);
	virtual float modifyValue(INamedObject *res, float value);
	
	ResourcePair *getResources();
	int setResources(ResourcePair *resources, bool merge = false);

	void addAllResources();

	ResourcePair buyingResults(ResourcePair *costs);

	static bool canAfford(ResourcePair *resources);
	void displayResources();
	static void displayResourcePair(ResourcePair *pair);

protected:
	ResourcePair m_resources;
};
