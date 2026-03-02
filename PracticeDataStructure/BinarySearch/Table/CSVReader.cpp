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

	if (file.good())
	{
		m_header = ReadRow(file, ',');
	}

	while (file.good())
	{
		std::vector<std::string> row = ReadRow(file, ',');
		if (!row.empty())
		{
			m_readData.push_back(row);
		}
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
		else if (c == detemine && !inqutoes)
		{
			//구분자 만나면 현재까지의 값을 셀로 저장
			row.push_back(ss.str());
			ss.str("");
			ss.clear();
		}
		else if ((c == '\n' || c == '\r') && !inqutoes)
		{
			//줄바꿈 처리
			if (c == '\r' && file.peek() == '\n')
			{
				file.get();
			}

			//마지막 셀에 저장
			row.push_back(ss.str());
			return row;
		}
		else
		{
			ss << c;
		}
	}

	// 파일 끝에 줄바꿈 없이 끝나는 경우
	if (ss.str().size() > 0)
	{
		row.push_back(ss.str());
	}

	return row;
}
