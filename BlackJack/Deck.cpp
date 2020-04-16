#include "Deck.h"
#include <iomanip>
#include <iostream>

Deck::Deck(int deckCount)
{
	this->deckCount = deckCount;
	bool isAce = false;
	deck = new Card[NUM_OF_CARDS * deckCount];
	for (int i = 0; i < deckCount; i++)
	{
		for (int cardCount = 0; cardCount < NUM_OF_CARDS; cardCount++)
		{
			int cValue = (cardCount + 1) % 13;
			isAce = false;
			if (cValue == 1)
			{
				cValue += 10;
				isAce = true;
			}
			else if (cValue >= 10)
			{
				cValue = 10;
				isAce = false;
			}
			else if (cValue == 0)
			{
				cValue = 10;
				isAce = false;
			}
			deck[cardCount + (i * NUM_OF_CARDS)] = Card(dFaces[cardCount % 13], dSuits[cardCount / 13], cValue, isAce);
		}
	}
}

void Deck::printDeck() const
{
	for (int cardCount = 0; cardCount < NUM_OF_CARDS * deckCount; cardCount++)
	{
		std::cout << std::setw(20) << deck[cardCount].print();
		if ((cardCount + 1) % 4 == 0)
			std::cout << std::endl;
	}
}

void Deck::shuffle()
{
	currentCard = 0;
	dealtIndex.clear();
	for (int firstCard = 0; firstCard < NUM_OF_CARDS * deckCount; firstCard++)
	{
		int randCard = (std::rand() + time(0)) % NUM_OF_CARDS;
		std::swap(deck[firstCard], deck[randCard]);
	}
}

Card Deck::dealFromTop()
{
	return deck[currentCard++];
}

Card Deck::dealRandom()
{
	int rIndex;
	while (true)
	{
		rIndex = (std::rand() + time(0)) % NUM_OF_CARDS * deckCount;
		if (dealtIndex.empty())
			break;

		bool found = false;
		for (int i = 0; i < dealtIndex.size(); i++)
		{
			if (dealtIndex[i] == rIndex)
			{
				found = true;
				continue;
			}
		}
		if (!found)
			break;
	}
	dealtIndex.push_back(rIndex);
	return deck[rIndex];
}

int Deck::cardsDealt() const
{
	return currentCard;
}
