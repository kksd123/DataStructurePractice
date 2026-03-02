#include "ItemManager.h"

ItemManager::ItemManager()
{

}

ItemManager::~ItemManager()
{

}

bool ItemManager::LoadFromCSV(const std::string& filePath)
{
	CSVReader reader;
	if (!reader.ReadFile(filePath))
	{
		__debugbreak();
		return false;
	}

	const auto& data = reader.GetData();

	for (const auto& row : data)
	{
		if (row.size() < 3)
			continue;

		std::string key = row[0];
		//공백 제거
		key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
		ItemData itemData;
		itemData.name = row[0];
		itemData.type = std::stoi(row[1]);
		itemData.value = std::stoi(row[2]);
		m_table.Add(key, itemData);
	}

	return true;
}

void ItemManager::OnAdd(const std::string& name, int type, int value)
{
	system("cls");
	ItemData item;
	item.name = name;
	item.type = type;
	item.value = value;

	m_table.Add(name, item);
	std::cout << "Added: " << name << " [" << GetTypeName(type) << "] x" << value << "\n";
}

void ItemManager::OnRemove(const std::string& name)
{
	system("cls");
	if (m_table.Delete(name))
	{
		std::cout << "Removed: " << name << "\n";
	}
	else
	{
		std::cout << "Not found \n";
	}
}

void ItemManager::OnFind(const std::string& name)
{
	system("cls");
	Pair<std::string, ItemData> entry;
	if (!m_table.Find(name, entry))
	{
		std::cout << "Not found: " << name << "\n";
	}

	std::cout << entry.value.name
		<< " | " << GetTypeName(entry.value.type)
		<< " | x" << entry.value.value << "\n";
}

void ItemManager::OnList()
{
	system("cls");
	auto allData = m_table.GetAll();

	if (allData.empty())
	{
		std::cout << "Empty!\n";
		return;
	}

	for (const auto& entry : allData)
	{
		std::cout << entry.value.name
			<< " | " << GetTypeName(entry.value.type)
			<< " | x" << entry.value.value << "\n";
	}

	std::cout << "Total: " << allData.size() << "\n";
}

std::string ItemManager::GetTypeName(int type)
{
	switch (static_cast<eItemType>(type))
	{
	case eItemType::Weapon:
		return "Weapon";
	case eItemType::Armor:
		return "Armor";
	case eItemType::Consumable:
		return "Consumable";
	case eItemType::Book:
		return "Book";
	case eItemType::Material:
		return "Material";
	case eItemType::Accessory:
		return "Accessory";
	default:
		return "Etc";
	}
	return std::string();
}
