#pragma once
#include "Pair.h"
#include <vector>
#include <string>

template<typename T>
class HashTable
{
private:
	using Entry = Pair<std::string, T>;


public:
	HashTable(int initCapacity = 7)
		: m_capacity(initCapacity)
		, m_size(0)
	{
		m_table = new std::vector<Entry>[m_capacity];
	}

	~HashTable()
	{
		delete[] m_table;
	}

	bool Add(const std::string& key, const T& value)
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

		float loadFactor = (float)m_size / m_capacity;
		if (loadFactor > sc_maxLoadFactor)
		{
			ReHash();
		}

		return true;
	}

	bool Delete(const std::string& key)
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

	bool Find(const std::string& key, Entry& outEntry)
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

	bool IsEmpty() const
	{
		return m_size <= 0;
	}

	//list 명령어 처리를 위해 모든 데이터 가져오는 함수 
	std::vector<Entry> GetAll() const
	{
		std::vector<Entry> result;
		for (int i = 0; i < m_capacity; i++)
		{
			for (const auto& entry : m_table[i])
			{
				result.emplace_back(entry);
			}
		}

		return result;
	}

private:
	int GenerateHash(const std::string& keyString) const
	{
		int hash = 0;
		for (char c : keyString)
		{
			hash = hash * 31 + (int)c;
		}
		return std::abs(hash) % m_capacity;
	}

	void ReHash()
	{
		int oldCapacity = m_capacity;
		std::vector<Entry>* oldTable = m_table;

		m_capacity = oldCapacity * 2 + 1;
		m_table = new std::vector<Entry>[m_capacity];
		m_size = 0;

		for (int i = 0; i < oldCapacity; ++i)
		{
			for (const auto& entry : oldTable[i])
			{
				Add(entry.key, entry.value);
			}
		}

		delete[] oldTable;
	}

private:
	static constexpr float sc_maxLoadFactor = 0.75f;
	std::vector<Entry>* m_table;
	int m_capacity;
	int m_size;
};

