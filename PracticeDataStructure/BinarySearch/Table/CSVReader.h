#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class CSVReader
{
public:
	CSVReader();
	~CSVReader();

	bool ReadFile(const std::string& filePath);

	const std::vector<std::vector<std::string>>& GetData() const { return m_readData; }
	const std::vector<std::string>& GetHeader() const { return m_header; }
	
private:
	std::vector<std::string> ReadRow(std::ifstream &file, const char detemine);

private:
	std::vector<std::string> m_header;
	std::vector<std::vector<std::string>> m_readData;
};
