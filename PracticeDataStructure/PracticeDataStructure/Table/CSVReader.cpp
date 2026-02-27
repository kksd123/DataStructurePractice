#pragma once
#include "CSVReader.h"

CSVReader::CSVReader()
{
}

CSVReader::~CSVReader()
{
}

bool CSVReader::ReadFile(const std::string& filePath)
{
	std::ifstream file(filePath);

	if (file.is_open() == false)
	{
		std::cout << "파일 경로가 없습니다.\n";
		return false;
	}

	while (file.good())
	{
		ReadRow(file, ',');
	}

	file.close();

	return true;
}

std::vector<std::string> CSVReader::ReadRow(std::ifstream &file, const char detemine)
{
	std::stringstream ss;
	bool inqutoes = false;
	std::vector<std::string> row;

	while (file.good())
	{
		char c = file.get();

		if (c == '"' && !inqutoes)
		{
			inqutoes = true;
		}
		else if (inqutoes && c == '"')
		{
			if (file.peek() == '"')
			{
				ss << file.get();
			}
			else
			{
				inqutoes = false;
			}
		}
	}

	return std::vector<std::string>();
}
