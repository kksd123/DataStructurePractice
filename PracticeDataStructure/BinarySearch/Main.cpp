#include "Src/ScoreManager.h"

int main()
{
	ScoreManager manager;
	manager.LoadFromCSV("Table/PlayerScores.txt");
	manager.Run();
}