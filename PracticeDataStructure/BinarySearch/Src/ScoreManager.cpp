#include "ScoreManager.h"
#include <algorithm>

ScoreManager::ScoreManager()
{
}

ScoreManager::~ScoreManager()
{
}

bool ScoreManager::LoadFromCSV(const std::string& filePath)
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
		if (row.size() < 2)
			continue;

		PlayerData info;
		//stoi : string -> int
		info.name = row[0];
		info.score = std::stoi(row[1]);

		m_players.emplace_back(info);
	}

	std::sort(m_players.begin(), m_players.end(),
		[](const PlayerData& p1, const PlayerData& p2)
		{
			return p1.name < p2.name;
		});

	return true;
}

void ScoreManager::OnInsert(const std::string& name, int score)
{

}

void ScoreManager::OnDelete(const std::string& name)
{

}

void ScoreManager::OnFind(const std::string& name)
{

}

void ScoreManager::OnTop(int k)
{

}