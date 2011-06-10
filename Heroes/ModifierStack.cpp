#include "ModifierStack.h"

bool ModifierStack::addModifier(Modifier *modifier)
{
	if(modifier->getType() >= NUM_MODIFIERS)
	{	
		return false;
	}
	pair<ModifierSet::iterator, bool> result = m_modifiers[modifier->getType()].insert(modifier);
	return result.second;
}

bool ModifierStack::removeModifier(Modifier *modifier)
{
	if(modifier->getType() >= NUM_MODIFIERS)
	{
		return false;
	}
	return m_modifiers[modifier->getType()].erase(modifier) > 0;
}

ModifierStackResult ModifierStack::getModifierValues()
{
	float addStack = 0.0f;
	ModifierSet::iterator iter = m_modifiers[ADD_STACKS].begin();
	while(iter != m_modifiers[ADD_STACKS].end())
	{
		addStack += (*iter)->getModifyValue();
		iter++;
	}

	float percentStack = 0.0f;
	iter = m_modifiers[ADD_PERCENTAGE_STACKS].begin();
	while(iter != m_modifiers[ADD_PERCENTAGE_STACKS].end())
	{
		percentStack += (*iter)->getModifyValue();
		iter++;
	}

	float percentNoStack = 0.0f;
	iter = m_modifiers[ADD_PERCENTAGE_NO_STACKS].begin();
	while(iter != m_modifiers[ADD_PERCENTAGE_NO_STACKS].end())
	{
		percentNoStack = max(percentNoStack, (*iter)->getModifyValue());
		iter++;
	}

	float percent = max(percentStack, percentNoStack);

	return ModifierStackResult(addStack, percentStack, percentNoStack);
}

float ModifierStack::modifyValue(float value)
{
	ModifierStackResult modifiers = getModifierValues();
	return value + modifiers.addStacks + value * max(modifiers.percentNoStacks, modifiers.percentStacks);
}