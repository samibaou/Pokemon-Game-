#include "TrainerCard.h"


TrainerCard::TrainerCard(string nom, string trainerEffect): Card(nom), trainerEffect(trainerEffect){}
string TrainerCard::getTrainerEffect() {
	return trainerEffect;
}
void TrainerCard::displayInfo() {
	cout << "cardName: " << getcardName() << endl
		<< "pokemonType:" << trainerEffect << endl;
}