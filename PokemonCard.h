#ifndef CARDPOKEMON_H
#define CARDPOKEMON_H
#include "Card.h"
#include "EnergyCard.h"
#include <vector>
#include <tuple>


class PokemonCard : public Card{
private:
	string pokemonType;
	string familyName;
	int evolutionLevel;
	int maxHP;
	int hp;
	vector<tuple<int, int, string, int>> attacks;
	vector<EnergyCard*> attachedEnergies;
public:
	PokemonCard(string, string, string,int,int,int, string, int, int,
		string, int);
	int getHp();
	void setHp(int amount);
	tuple<int, int, string, int> getAttack(int i);
	void reduceHP(int amount);
	int getMaxHp();
	void attachEnergy(EnergyCard*);
	void displayInfo() override;
};
#endif