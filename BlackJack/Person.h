#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "Deck.h"

class Person
{
private:
	void addValue(const Card&);

protected:
	static Deck* mDeck;
	int dCount = 0;
	int tCount = 0;
	int aceCount = 0;
	std::vector<Card> drawnCard;
	std::string pName;
	void printValue();
public:
	virtual ~Person() = 0;
	void hit();
	std::string name() const;
	virtual void initialDraw() = 0;
	virtual void showInitialHand() = 0;
	int totalCount(); //req
	int drawCount();  //req
	void reset();     //req
};

#endif