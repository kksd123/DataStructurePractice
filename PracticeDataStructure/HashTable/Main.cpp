#include "Src/ItemManager.h"

int main()
{
	ItemManager manager;
	manager.LoadFromCSV("Table/ItemData.txt");
	manager.Run();
}