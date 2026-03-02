#include "HashTable.h"

HashTable::HashTable(int initCapacity)
	:m_capacity(initCapacity)
	,m_size(0)
{
	m_table = new std::vector<Entry>[m_capacity];
}

HashTable::~HashTable()
{
	delete[] m_table;
}

int HashTable::GenerateHash(const std::string& keyString) const
{
	int hash = 0;
	for (char c : keyString)
	{
		hash = hash * 31 + (int)c;
	}

	return std::abs(hash) % m_capacity;
}

void HashTable::ReHash()
{
	int oldCapacity = m_capacity;
	std::vector<Entry>* oldTable = m_table;

	// 용량 2배 + 1 (홀수 유지)
	m_capacity = oldCapacity * 2 + 1;
	m_table = new std::vector<Entry>[m_capacity];
	m_size = 0;

	// 기존 데이터 재삽입
	for (int i = 0; i < oldCapacity; ++i)
	{
		for (const auto& entry : oldTable[i])
		{
			Add(entry.key, entry.value);
		}
	}

	delete[] oldTable;
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
	int idx = GenerateHash(key);

	for (Entry& entry : m_table[idx])
	{
		if (entry.key == key)
		{
			entry.value = value;
			return true;
		}
	}

	m_table[idx].push_back(Entry(key, value));
	++m_size;

	// 적재율 초과시 리해싱
	float loadFactor = (float)m_size / m_capacity;
	if (loadFactor > sc_maxLoadFactor)
	{
		ReHash();
	}

	return true;
}

bool HashTable::Delete(const std::string& key)
{
	int idx = GenerateHash(key);

	auto& bucket = m_table[idx];
	for (auto it = bucket.begin(); it != bucket.end(); it++)
	{
		if (it->key == key)
		{
			bucket.erase(it);
			--m_size;
			return true;
		}
	}

	return false;
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{
	int idx = GenerateHash(key);

	for (Entry& entry : m_table[idx])
	{
		if (entry.key == key)
		{
			outEntry = entry;
			return true;
		}
	}

	return false;
}

bool HashTable::IsEmpty() const
{
	return m_size <= 0;
}
