#pragma once

#include <string>
#include <sstream>

using namespace std;

#define ADD_STACKS					0
#define ADD_PERCENTAGE_STACKS		1
#define ADD_PERCENTAGE_NO_STACKS	2

#define NUM_MODIFIERS	3

class Modifier
{
public:
	Modifier()
	{
		m_type = ADD_STACKS;
		m_value = 1.0f;
		m_modifier_name = "STAT";
		m_dirty_desc = true;
		m_description = "";
	}
	Modifier(int type, float value)
	{
		m_type = type;
		m_value = value;
		m_modifier_name = "STAT";
		m_dirty_desc = true;
		m_description = "";
	}
	Modifier(int type, float value, string name)
	{
		m_type = type;
		m_value = value;
		m_modifier_name = name;
		m_dirty_desc = true;
		m_description = "";
	}
	~Modifier() {}

	inline int getType() { return m_type; }
	inline void setType(int type) { m_type = type; m_dirty_desc = true; }

	inline string getDescription()
	{
		if(m_dirty_desc)
			updateDescription();
		return m_description;
	}
	
	inline string getModifierName() { return m_modifier_name; }
	inline void setModifierName(string name) { m_modifier_name = name; m_dirty_desc = true; }

	inline float getValue() { return m_value; }
	inline void setValue(float value) { m_value = value; m_dirty_desc = true; }

	inline float getModifyValue()
	{
		if(m_type == ADD_STACKS)
		{
			return m_value;
		}
		else
		{
			return m_value - 1.0f;
		}
	}

protected:

	bool m_dirty_desc;
	int m_type;
	string m_description;
	string m_modifier_name;
	float m_value;

	void updateDescription()
	{
		m_dirty_desc = false;
		stringstream ss;
		float cutOff = 0.0f;
		if(m_type != ADD_STACKS)
		{
			cutOff = 1.0f;
		}

		if(m_value < cutOff)
		{
			ss << "Reduces " << m_modifier_name << " by ";
		}
		else
		{
			ss << "Adds ";
		}

		if(m_type == ADD_STACKS)
		{
			ss << m_value;
		}
		else
		{
			ss << abs(m_value - 1.0f) * 100.0f << "%";
		}

		if(m_value < cutOff)
		{
			ss << ".";
		}
		else
		{
			ss << " to " << m_modifier_name << ".";
		}

		if(m_type == ADD_PERCENTAGE_NO_STACKS)
		{
			ss << " Does not stack.";
		}
		m_description = ss.str();
	}
};
