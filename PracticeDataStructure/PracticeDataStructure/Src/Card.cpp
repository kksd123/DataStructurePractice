#include "Card.h"

Card::Card()
{
}

Card::~Card()
{
}

bool Card::LoadFromeCSV(const std::string& filePath)
{
	CSVReader reader;
	if (!reader.ReadFile(filePath))
	{
		__debugbreak();
		return false;
	}

	const auto& data = reader.GetData();

	for (const auto& row : data)
	{
		if (row.size() < 5)
			continue;

		CardInfo info;
		//stoi : string -> int
		info.id = std::stoi(row[0]);
		info.name = row[1];
		info.type = row[2];
		info.cost = std::stoi(row[3]);
		info.rarity = std::stoi(row[4]);

		m_cardDatas.emplace_back(info);
	}

	return true;
}
