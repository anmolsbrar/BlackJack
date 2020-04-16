#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>

const int NUM_OF_CARDS = 52;
const int SUITS = 4;
const int FACES = 13;

class Deck
{
private:
	int currentCard = 0;
	bool isAce;
	int deckCount;
	std::string dFaces[FACES] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
	std::string dSuits[SUITS] = { "Spades", "Clubs", "Diamonds", "Hearts" };
	std::vector<int> dealtIndex;
	Card* deck;
public:
	Deck(int);
	void printDeck() const;
	void shuffle();
	Card dealFromTop();
	Card dealRandom();
	int cardsDealt() const;
};

#endif