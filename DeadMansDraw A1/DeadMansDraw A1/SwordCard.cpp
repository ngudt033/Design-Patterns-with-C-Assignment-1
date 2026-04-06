#include "SwordCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

SwordCard::SwordCard(int value) : Card(value, CardType::Sword) {

}

std::string SwordCard::str() const {
	return "Sword(" + std::to_string(getValue()) + ")";
}

void SwordCard::play(Game& game, Player& player) {
	Player* opponent = game.getOtherPlayer();
	CardCollection& opponentBank = opponent->getBank();

	if (opponentBank.empty()) {
		std::cout << "Sword: Unable to steal highest value card from opponent's bank, opponent's bank is empty.";
		return;
	}
	
	int highestValue = 0;

	for (int i = 1; i < (int)opponentBank.size(); i++) {
		if (opponentBank[i]->getValue() > opponentBank[highestValue]->getValue()) {
			highestValue = i;
		}
	}

	Card* stolenCard = opponent->removeBankCard(highestValue);
	std::cout << "Sword: Stolen " << stolenCard->str() << " from opponent's bank." << std::endl;
	
	player.addCardToPlayArea(stolenCard);

	if (player.isBust()) {
		std::cout << player.getName() << " busted after stealing " << stolenCard->str() << "!" << std::endl;
		return;
	}
	stolenCard->play(game, player);
}
