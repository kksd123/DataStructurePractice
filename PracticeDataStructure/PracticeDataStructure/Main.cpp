#include <iostream>
#include "Table/CSVReader.h"

int main()
{
	CSVReader reader;

	reader.ReadFile("Table/CardData.txt");
	std::cin.get();
}