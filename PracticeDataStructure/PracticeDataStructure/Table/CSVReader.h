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
	
private:
	std::vector<std::string> ReadRow(std::ifstream &file, const char detemine);

private:
	std::vector<std::string> m_readData;
};
