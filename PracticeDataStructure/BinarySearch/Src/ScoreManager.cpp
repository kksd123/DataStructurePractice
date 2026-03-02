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
	PlayerData player;
	player.name = name;
	player.score = score;

	int pos = m_searcher.FindInsertPos(m_players, name);
	m_players.insert(m_players.begin() + pos, player);

	system("cls");
	std::cout << "Inserted: " << name << " (" << score << ")\n";
}

void ScoreManager::OnDelete(const std::string& name)
{
	int idx = m_searcher.FindByName(m_players, name);

	if (idx == -1)
	{
		std::cout << "Not found!" << "\n";
		return;
	}

	system("cls");
	m_players.erase(m_players.begin() + idx);
	std::cout << "Deleted: " << name << "\n";
}

void ScoreManager::OnFind(const std::string& name)
{
	int idx = m_searcher.FindByName(m_players, name);

	if (idx == -1)
	{
		std::cout << "Not found!" << "\n";
		return;
	}

	system("cls");
	std::cout << m_players[idx].name << " : " << m_players[idx].score << "\n";
}

void ScoreManager::OnTop(int k)
{
	//점수 기준으로 정렬 작업 진행
	std::vector<PlayerData> sorted = m_players;
	std::sort(sorted.begin(), sorted.end(),
		[](const PlayerData& p1, const PlayerData& p2)
		{
			return p1.score > p2.score;
		});

	system("cls");
	for (int i = 0; i < k; i++)
	{
		std::cout << i + 1 << ". " << sorted[i].name
			<< " : " << sorted[i].score << "\n";
	}
}