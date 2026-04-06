#include "CannonCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

CannonCard::CannonCard(int value) : Card(value, CardType::Cannon) {

}

std::string CannonCard::str() const {
	return "Cannon(" + std::to_string(getValue()) + ")";
}

void CannonCard::play(Game& game, Player& player) {
	Player* opponent = game.getOtherPlayer();
	CardCollection& opponentBank = opponent->getBank();

	if (opponentBank.empty()) {
		std::cout << "Cannon: Unable to discard highest value card from opponent's bank, opponent's bank is empty." << std::endl;
	}
	
	int highestValue = 0;

	for (int i = 1; i < (int)opponentBank.size(); i++) {
		if (opponentBank[i]->getValue() > opponentBank[highestValue]->getValue()) {
			highestValue = i;
		}
	}
	Card* discardedCard = opponent->removeBankCard(highestValue);

	std::cout << "Cannon: Discarded " << discardedCard->str() << " from opponent's bank." << std::endl;
}