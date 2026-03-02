#pragma once
#include "../Common/IConsoleCommand.h"
#include "../Src/ItemData.h"
#include "../Table/CSVReader.h"
#include "../Common/HashTable.h"

class ItemManager : public IConsoleCommand
{
public:
	ItemManager();
	~ItemManager();

	bool LoadFromCSV(const std::string& filePath);

protected:
	void OnAdd(const std::string& name, int type, int value) override;
	void OnRemove(const std::string& name) override;
	void OnFind(const std::string& name) override;
	void OnList() override;

private:
	//EnumClass ¥Î¿¿
	std::string GetTypeName(int Type);

private:
	HashTable<ItemData> m_table;
};

