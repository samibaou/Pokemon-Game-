#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(string cardName,string pokemonType,
string familyName,
int evolutionLevel,
int maxHP,
int hp,
string attack1Desc, int attack1Energy, int attack1ActualEnergy,
string attack2Desc, int attack2Energy): Card(cardName),
	pokemonType(pokemonType),
	familyName(familyName), 
	evolutionLevel(evolutionLevel),
	maxHP(maxHP),hp(hp){
	attacks.push_back({ attack1Energy, attack1ActualEnergy, attack1Desc, 0 });
	attacks.push_back({ attack2Energy, 0, attack2Desc, attack2Energy });
}
void PokemonCard::attachEnergy(EnergyCard* e) {
	attachedEnergies.push_back(e);
}
tuple<int, int, string, int> PokemonCard::getAttack(int i) {
	return attacks[i];
}

void PokemonCard::reduceHP(int amount) {
	hp -= amount;
	if (hp < 0) hp = 0;
}

int PokemonCard::getHp(){ return hp; }
void PokemonCard::setHp(int amount) { hp=amount; }
int PokemonCard::getMaxHp() { return maxHP; }

void PokemonCard::displayInfo() {
	cout << "cardName: " << getcardName() << endl
		<< "pokemonType:" << pokemonType << endl
		<< "familyName:" << familyName << endl
		<< "evolutionLevel:" << evolutionLevel << endl
		<< "maxHP:" << maxHP << endl
		<< "hp:" << hp << endl
		<< "attacks:" << endl;
	for (tuple<int, int, string, int> attack : attacks)
		cout << endl << "attack description: " << get<2>(attack) << endl
		<< "Energie cost: " << get<0>(attack) << endl
		<< "Current Energie cost: " << get<1>(attack) << endl
		<< "Attack damage: " << get<3>(attack) << endl;
};