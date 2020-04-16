#include "Player.h"
#include <iostream>
#include <iomanip>

Player::Player(const std::string& name)
{
	pName = name;
	tCount = 0;
	dCount = 0;
}

Player::Player(int pNum)
{
	pName = "Player " + std::to_string(pNum);
	tCount = 0;
	dCount = 0;
}

Player::~Player()
{
}


void Player::initialDraw()
{
	for (int i = 0; i < 2; i++)
	{
		Card hCard = mDeck->dealFromTop();
		drawnCard.push_back(hCard);
		tCount += hCard.getValue();
		dCount++;

		if (hCard.isAce())
			aceCount++;

		if (aceCount > 1)
			tCount -= 10;
	}

	showInitialHand();
}

void Player::showInitialHand()
{
	std::cout << drawnCard[0].print() << std::endl;
	std::cout << drawnCard[1].print() << std::endl;
	printValue();
}


