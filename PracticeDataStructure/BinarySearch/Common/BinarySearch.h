#pragma once
#include <string>
#include <vector>

template<typename T>
class BinarySearch
{
public:
	int FindByName(const std::vector<T>& data, const std::string& name);

	int FindInsertPos(const std::vector<T>& data, const std::string& name);
};

