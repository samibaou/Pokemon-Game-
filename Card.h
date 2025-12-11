#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card
{
private:
	string cardName;
public:
	Card();
	Card(string);
	string getcardName();
	virtual void displayInfo() = 0;
};
#endif