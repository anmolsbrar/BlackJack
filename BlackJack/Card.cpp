#include "Card.h"

Card::Card(const std::string& cardFace, const std::string& cardSuit, int cardValue, bool isAce) :
	face(cardFace), suit(cardSuit), value(cardValue), ace(isAce) {}

Card::Card() : face("Null"), suit("Null"), value(0), ace(false) {}

std::string Card::print() const
{
	return face + " of " + suit;
}

int Card::getValue() const
{
	return value;
}

bool Card::isAce() const
{
	return ace;
}
