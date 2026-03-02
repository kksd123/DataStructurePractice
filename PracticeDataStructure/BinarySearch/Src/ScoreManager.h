#pragma once
#include "../Common/IConsoleCommand.h"
#include "../Common/BinarySearch.h"
#include "../Table/CSVReader.h"
#include "PlayerData.h"

class ScoreManager : public IConsoleCommand
{
public:
	ScoreManager();
	~ScoreManager();

	bool LoadFromCSV(const std::string& filePath);

protected:
	void OnInsert(const std::string& name, int score) override;
	void OnDelete(const std::string& name) override;
	void OnFind(const std::string& name) override;
	void OnTop(int k) override;

private:
	std::vector<PlayerData> m_players;
	BinarySearch<PlayerData> m_searcher;
};

