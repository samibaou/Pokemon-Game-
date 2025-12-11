#include "EnergyCard.h"

EnergyCard::EnergyCard(string energyType):Card("Energy"),energyType(energyType){}
string EnergyCard::getEnergyType() {
	return energyType;
}
void EnergyCard::displayInfo() {
	cout << "cardName: " << getcardName() << endl
		<< "energyType:" << energyType << endl;
}