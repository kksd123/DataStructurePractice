#pragma once
#include <string>
#include <vector>
#include "../Table/CSVReader.h"

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
	Card();
	~Card();

	bool LoadFromeCSV(const std::string& filePath);

	const std::vector<CardInfo> GetCardData() const
	{
		return m_cardDatas;
	}

private:
	std::vector<CardInfo> m_cardDatas;
};