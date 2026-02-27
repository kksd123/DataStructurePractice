#pragma once
#include <string>
#include <vector>

class Card
{
	struct CardInfo
	{
		int id;
		std::string name;
		std::string type;
		int cost;
		int rarity;
	};

public:
	bool CreateTable();

	const std::vector<CardInfo> GetCardData() const
	{
		return m_cardDatas;
	}

private:
	std::vector<CardInfo> m_cardDatas;
};