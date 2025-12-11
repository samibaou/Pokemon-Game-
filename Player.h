#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "PokemonCard.h"
#include "TrainerCard.h"

using namespace std;

class Player
{
private:
	string playerName;
	vector<Card*> benchCards;
	vector<PokemonCard*> actionCard;
public:
	Player(string);
	void addCardToBench(Card*);
	void activatePokemonCard(long);
	void attachEnergyCard(long, long);
	void displayBench();
	void displayAction();
	void attack(long, long, Player&, long);
	void useTrainer(long);
};
#endif
