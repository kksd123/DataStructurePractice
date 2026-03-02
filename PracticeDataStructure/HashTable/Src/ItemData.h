#pragma once
#include <string>

enum class eItemType
{
	Etc = 0,
	Weapon = 1,
	Armor = 2,
	Consumable = 3,
	Book = 4,
	Material = 5,
	Accessory = 6,
};

struct ItemData
{
	std::string name;
	int type;
	int value;
};