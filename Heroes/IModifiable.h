#pragma once

#include "INamedObject.h"

#include "Modifier.h"
#include "ModifierStack.h"

#include <string>
#include <map>

using namespace std;

typedef map<string, ModifierStack> ModifierPair;

class IModifiable
{
public:
	virtual bool addModifier(string objShortName, Modifier *modifier) = 0;
	virtual bool addModifier(INamedObject *obj, Modifier *modifier) = 0;
	virtual bool removeModifier(string objShortName, Modifier *modifier) = 0;
	virtual bool removeModifier(INamedObject *obj, Modifier *modifier) = 0;
	virtual float modifyValue(string objShortName, float value) = 0;
	virtual float modifyValue(INamedObject *obj, float value) = 0;

protected:
	ModifierPair m_modifiers;
};
