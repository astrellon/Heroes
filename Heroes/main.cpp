#include <iostream>

using namespace std;

#include "Stat.h"
#include "Player.h"
#include "Resource.h"
#include "Building.h"
#include "Town.h"
#include "Hero.h"
#include "Modifier.h"
#include "ModifierStack.h"
#include "Item.h"

int main()
{
	Stat::addDefaultStats();
	Resource::addDefaultResources();
	Building::addDefaultBuildings();

	Town t("Boogie");
	t.setBuildingAvailability("vhall", true);
	t.setBuildingAvailability("thall", true);
	t.setBuildingAvailability("mplace", true);

	Player p;

	Hero h("Melli");
	h.getStats()->setStat(Stat::ATTACK, 10);
	h.getStats()->setStat(Stat::DEFENCE, 10);
	h.getStats()->setStat(Stat::SPELLPOWER, 10);
	h.getStats()->setStat(Stat::KNOWLEDGE, 10);

	Modifier m(0, 3);

	h.getStats()->addModifier(Stat::ATTACK, &m);
	h.getStats()->addModifier(Stat::ATTACK, new Modifier(ADD_PERCENTAGE_STACKS, 1.5));

	h.addExperience(10000);
	h.displayInfo();

	m.setValue(6);
	h.displayInfo();

	//Item i("Sword");
	//i.getStatModifiers();

	//float v = s.modifyValue(10);
	//cout << "Base: " << 10 << ", Modified: " << v << endl;
	
	getchar();

	return 0;
}