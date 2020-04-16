#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"

class Player :public Person
{
private:
	//std::string pName;
public:
	Player(const std::string&);
	Player(int);
	~Player();
	void initialDraw() override;
	void showInitialHand() override;
};

#endif