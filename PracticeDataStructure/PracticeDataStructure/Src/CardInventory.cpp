#include "CardInventory.h"

CardInventory::CardInventory()
{
	Card card;
	card.LoadFromeCSV("Table/CardData.txt");
	m_cardData = card.GetCardData();
	m_cardLength = m_cardData.size();
	m_currentIndex = 0;
}

CardInventory::~CardInventory()
{
}

void CardInventory::OnLeftKey()
{
	--m_currentIndex;

	if (m_currentIndex < 0)
	{
		m_currentIndex = m_cardLength - 1;
	}

	PrintCard();
}

void CardInventory::OnRightKey()
{
	++m_currentIndex;

	if (m_currentIndex >= m_cardLength)
	{
		m_currentIndex = 0;
	}

	PrintCard();
}

void CardInventory::PrintCard()
{
	system("cls");
	std::cout << "id : " << m_cardData[m_currentIndex].id << "\n";
	std::cout << "cost : " << m_cardData[m_currentIndex].cost << "\n";
	std::cout << "name : " << m_cardData[m_currentIndex].name << "\n";
	std::cout << "rarity : " << m_cardData[m_currentIndex].rarity << "\n";
	std::cout << "type : " << m_cardData[m_currentIndex].type << "\n";
}
