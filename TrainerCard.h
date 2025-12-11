#ifndef TRAINER
#define TRAINER
#include "Card.h"

class TrainerCard : public Card{
private:
	string nom;
	string trainerEffect;
public:
	TrainerCard(string,string);
	string getTrainerEffect();
	void displayInfo() override;
	virtual ~TrainerCard() = default;
};
#endif