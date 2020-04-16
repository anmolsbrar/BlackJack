#include "Dealer.h"
#include <iomanip>
#include <iostream>

Dealer::Dealer()
{
	pName = "Dealer";
	tCount = 0;
	dCount = 0;
}

Dealer::~Dealer()
{
	delete mDeck;
}

void Dealer::shuffle()
{
	mDeck->shuffle();
}

int Dealer::upCardValue() const
{
	return drawnCard[0].getValue();
}


void Dealer::initialDraw()
{
	Card hCard = mDeck->dealFromTop();
	drawnCard.push_back(hCard);
	tCount += hCard.getValue();
	dCount++;

	if (hCard.isAce())
		aceCount++;

	showInitialHand();
}

void Dealer::showInitialHand()
{
	std::cout << drawnCard[0].print() << std::endl;
	printValue();
}

int Dealer::totalDealt() const
{
	return mDeck->cardsDealt();
}