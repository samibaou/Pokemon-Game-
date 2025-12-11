#ifndef ENERGY_H
#define ENERGY_H
#include "Card.h"

class EnergyCard : public Card
{
private:
	string energyType;
public:
	EnergyCard(string);
	void displayInfo() override;
	string getEnergyType();
	virtual ~EnergyCard() = default;
};
#endif
