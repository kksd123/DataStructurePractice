#pragma once
#include "Card.h"
#include "../Common/IKeyInputHandler.h"
class CardInventory : public IKeyInputHandler
{
public:
	CardInventory();
	~CardInventory();

	void PrintCard();

protected:
	void OnLeftKey() override;
	void OnRightKey() override;

private:
	int m_currentIndex = 0;
	std::vector<Card::CardInfo> m_cardData;
	int m_cardLength = 0;
};

