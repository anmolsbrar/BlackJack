#pragma once
#ifndef DEALER_H
#define DEALER_H

#include "Person.h"

class Dealer : public Person
{
public:
	Dealer();
	~Dealer();
	void shuffle();
	int upCardValue() const;
	void initialDraw() override;
	void showInitialHand() override;
	int totalDealt() const;
};

#endif