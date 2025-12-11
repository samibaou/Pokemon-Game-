#include "Player.h"

Player::Player(string playerName):playerName(playerName){}
void Player::addCardToBench(Card* card) {
	benchCards.push_back(card);
}
void Player::activatePokemonCard(long pos) {
	actionCard.push_back((PokemonCard*)benchCards.at(pos));
	cout << playerName << "is activating a Pokemon: " << ((PokemonCard*)benchCards.at(pos))->getcardName() << endl;
	benchCards.erase(benchCards.begin()+pos);
}
void Player::attachEnergyCard(long posEnergyCard, long posPokemonCard) {
	actionCard.at(posPokemonCard)->attachEnergy((EnergyCard*)benchCards.at(posEnergyCard));
	cout << playerName << "is attaching Energy Card of type " << ((EnergyCard*)benchCards.at(posEnergyCard))->getEnergyType() << "to the Pokemon " << actionCard.at(posPokemonCard)->getcardName() << endl;
	benchCards.erase(benchCards.begin() + posEnergyCard);
}
void Player::displayBench() {
	for (auto it : benchCards)
		it->displayInfo();
}
void Player::displayAction() {
	for (auto it : actionCard)
		it->displayInfo();
}
void Player::attack(long posPokemonCard1, long posattack, Player& enemy, long posPokemonCard2) {
    PokemonCard* attacker = actionCard[posPokemonCard1];
    PokemonCard* defender = enemy.actionCard[posPokemonCard2];
   
    tuple<int, int, string, int> atk = attacker->getAttack(posattack);
    int energyCost = get<0>(atk);
    int actualCost = get<1>(atk);
    string description = get<2>(atk);
    int damage = get<3>(atk);

    cout << playerName << " attacking " << enemy.playerName
        << "'s Pokemon " << defender->getcardName()
        << " with Pokemon " << attacker->getcardName()
        << " using attack: " << description << endl;

    defender->reduceHP(damage);

    cout << "Reducing " << damage << " from "
        << enemy.playerName << "'s Pokemon " << defender->getcardName()
        << "'s HP" << endl;

    if (defender->getHp() > 0) {
        cout << "Pokemon " << defender->getcardName()
            << " is still alive with " << defender->getHp() << " HP." << endl;
    }
    else {
        cout << "Pokemon " << defender->getcardName()
            << " is dead!" << endl;

        enemy.actionCard.erase(enemy.actionCard.begin() + posPokemonCard2);

        cout << defender->getcardName() << " has been removed from "
            << enemy.playerName << "'s active cards." << endl;
    }
}
void Player::useTrainer(long pos) {
    if(((TrainerCard*)benchCards.at(pos))->getTrainerEffect()=="heal all your action pokemon") {
        for (auto it : actionCard)
            it->setHp(it->getMaxHp());
        cout << playerName << "is using the trainer card to \"heal all your action pokemon\"" << endl;
        benchCards.erase(benchCards.begin() + pos);
    }
}