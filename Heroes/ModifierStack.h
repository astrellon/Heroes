#pragma once

#include "Modifier.h"
#include <set>

using namespace std;

typedef set<Modifier *> ModifierSet;

typedef struct _ModifierStackResult
{
	float addStacks;
	float percentStacks;
	float percentNoStacks;

	_ModifierStackResult(): addStacks(0.0f), percentNoStacks(0.0f), percentStacks(0.0f) {};
	_ModifierStackResult(float add, float percentStacks, float percentNoStacks): 
		addStacks(add), percentNoStacks(percentNoStacks), percentStacks(percentStacks) {};
} ModifierStackResult;

class ModifierStack
{
public:
	ModifierStack() {}
	~ModifierStack() {}

	inline ModifierSet *getAdds() { return &m_modifiers[ADD_STACKS]; }
	inline ModifierSet *getStackables() { return &m_modifiers[ADD_PERCENTAGE_STACKS]; }
	inline ModifierSet *getNonStackables() { return &m_modifiers[ADD_PERCENTAGE_NO_STACKS]; }

	ModifierStackResult getModifierValues();

	bool addModifier(Modifier *modifier);
	bool removeModifier(Modifier *modifier);

	float modifyValue(float value);

protected:

	ModifierSet m_modifiers[NUM_MODIFIERS];
};
