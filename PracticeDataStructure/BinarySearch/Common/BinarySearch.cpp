#include "BinarySearch.h"

template<typename T>
int BinarySearch<T>::FindByName(const std::vector<T>& data, const std::string& name)
{
	int start = 0;
	int end = (int)(data.size()) - 1;

	while (start <= end)
	{
		int mid(start + end) / 2;

		if (data[mid].name == name)
			return mid;
		else if (data[mid].name < name)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
}

template<typename T>
int BinarySearch<T>::FindInsertPos(const std::vector<T>& data, const std::string& name)
{
	int start = 0;
	int end = (int)(data.size());

	while (start <= end)
	{
		int mid(start + end) / 2;

		if (data[mid].name < name)
			start = mid + 1;
		else
			end = mid;
	}

	return start;
}