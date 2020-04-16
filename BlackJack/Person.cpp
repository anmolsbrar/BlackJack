#include "Person.h"
#include <iostream>
#include <iomanip>


Person::~Person() {}

std::string Person::name() const
{
	return pName;
}

int Person::totalCount()
{
	return tCount;
}

int Person::drawCount()
{
	return dCount;
}

void Person::reset()
{
	aceCount = 0;
	dCount = 0;
	tCount = 0;
	drawnCard.clear();
}



void Person::addValue(const Card& hCard)
{
	if (hCard.isAce())
	{
		aceCount++;
		if (aceCount == 1)
		{
			if ((tCount + hCard.getValue()) > 21)
			{
				tCount++;
				aceCount = 0;
			}
			else
				tCount += hCard.getValue();
		}
		else if (aceCount > 1)
		{
			tCount++;
		}
	}
	else
	{
		if (aceCount >= 1 && ((tCount + hCard.getValue()) > 21))
		{
			tCount += hCard.getValue() - 10;
			aceCount = 0;
		}
		else
			tCount += hCard.getValue();
	}
}

void Person::printValue()
{
	if (aceCount >= 1 && !(tCount > 21))
		std::cout << "Value: " << tCount - 10 << " or " << tCount << std::endl;
	else
		std::cout << "Value: " << tCount << std::endl;
}

void Person::hit()
{
	Card hCard;
	hCard = mDeck->dealFromTop();
	dCount++;

	addValue(hCard);
	std::cout << pName << " drew:" << std::setw(15) << hCard.print() << std::endl;
	printValue();
}
