#include "Card.h"

Card::Card():cardName("Pokemon"){}
Card::Card(string name):cardName(name){}
string Card::getcardName() {
	return cardName;
}