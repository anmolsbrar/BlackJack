#ifndef CARD_H
#define CARD_H
#include <string>	

class Card
{
private:
	std::string face;
	std::string suit;
	bool ace;
	int value;
public:
	Card(const std::string&, const std::string&, int, bool);
	Card();
	std::string print() const;
	int getValue() const;
	bool isAce() const;
};

#endif