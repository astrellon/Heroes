#pragma once

#include "Modifier.h"
#include "Hero.h"
#include "Player.h"

#include <string>
#include <map>

using namespace std;

typedef pair<string, Modifier *> ModifierItemPair;

class Item
{
public:
	Item() { setName(""); }
	Item(string name) { setName(name); }
	~Item() {}

	inline string getName() { return m_name; }
	inline void setName(string name) { m_name = name; }

	inline bool hasStatModifiers() { return !m_stat_modifiers.empty(); }
	inline bool hasResourceModifiers() { return !m_res_modifiers.empty(); }

	bool addStatModifier(INamedObject *obj, Modifier *modifier);
	bool removeStatModifier(INamedObject *obj, Modifier *modifier);

	bool addResourceModifier(INamedObject *obj, Modifier *modifier);
	bool removeResourceModifier(INamedObject *obj, Modifier *modifier);

	inline set<ModifierItemPair> *getStatModifiers() { return &m_stat_modifiers; }
	inline set<ModifierItemPair> *getResourceModifiers() { return &m_res_modifiers; }

protected:

	set<ModifierItemPair> m_stat_modifiers;
	set<ModifierItemPair> m_res_modifiers;
	string m_name;
};
