#include "Player.h"

Player::Player()
{
	m_resources.addAllResources();
}

void Player::displayResources()
{
	ResourcePair::iterator iter = m_resources.getResources()->begin();
	ResourcePair::iterator end = m_resources.getResources()->end();
	cout << "Resources:" << endl;
	bool empty = true;
	while(iter != end)
	{
		empty = false;
		Resource *resource = Resource::getResource(iter->first);
		if(resource == NULL)
		{
			cout << iter->first << " = " << iter->second << endl;
		}
		else
		{
			cout << resource->getFullName() << " = " << iter->second << endl;
		}
		iter++;
	}
	if(empty)
	{
		cout << "None" << endl;
	}
}

void Player::displayTowns()
{
	set<Town *>::iterator iter = m_owned_towns.begin();
	set<Town *>::iterator end = m_owned_towns.end();
	cout << "Towns:" << endl;
	bool empty = true;
	while(iter != end)
	{
		empty = false;
		cout << (*iter)->getName() << endl;
		
		iter++;
	}
	if(empty)
	{
		cout << "None" << endl;
	}
}

void Player::displayHeroes()
{
	set<Hero *>::iterator iter = m_owned_heroes.begin();
	set<Hero *>::iterator end = m_owned_heroes.end();
	cout << "Heroes:" << endl;
	bool empty = true;
	while(iter != end)
	{
		empty = false;
		cout << (*iter)->getName() << endl;
		
		iter++;
	}
	if(empty)
	{
		cout << "None" << endl;
	}
}

void Player::setTownOwnership(Town *town, bool ownership)
{
	if(town == NULL)
	{
		return;
	}
	// If the towns owner is this and we want to make it the owner again.
	if(town->getOwner() == this && ownership)
	{
		return;
	}

	set<Town *>::iterator iter = m_owned_towns.find(town);

	Player *oldOwner = town->getOwner();

	if(ownership)
	{
		if(iter == m_owned_towns.end())
		{
			m_owned_towns.insert(town);
			town->setOwner(this);
			if(oldOwner != NULL)
			{
				oldOwner->setTownOwnership(town, false);
			}
		}
	}
	else
	{
		if(iter != m_owned_towns.end())
		{
			m_owned_towns.erase(iter);
			town->setOwner(NULL);
		}
	}
}

void Player::setHeroOwnership(Hero *hero, bool ownership)
{
	if(hero == NULL)
	{
		return;
	}
	if(hero->getOwner() == this)
	{
		return;
	}

	set<Hero *>::iterator iter = m_owned_heroes.find(hero);
	Player *oldOwner = hero->getOwner();

	if(ownership)
	{
		if(iter == m_owned_heroes.end())
		{
			m_owned_heroes.insert(hero);
			hero->setOwner(this);
			if(oldOwner != NULL)
			{
				oldOwner->setHeroOwnership(hero, false);
			}
		}
	}
	else
	{
		if(iter != m_owned_heroes.end())
		{
			m_owned_heroes.erase(iter);
			hero->setOwner(NULL);
		}
	}
}