#pragma once
#include "Pair.h"
#include <vector>
#include <string>

class HashTable
{
private:
	using Entry = Pair<std::string, std::string>;

public:
	HashTable(int initCapacity = 7);
	~HashTable();

	bool Add(const std::string& key, const std::string& value);
	bool Delete(const std::string& key);
	bool Find(const std::string& key, Entry& outEntry);
	bool IsEmpty() const;

private:
	int GenerateHash(const std::string& keyString) const;
	void ReHash();

private:
	static constexpr float sc_maxLoadFactor = 0.75f;
	std::vector<Entry>* m_table;
	int m_capacity;
	int m_size;
};

