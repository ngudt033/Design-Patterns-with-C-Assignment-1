#include "HookCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

HookCard::HookCard(int value) : Card(value, CardType::Hook) {

}

std::string HookCard::str() const {
	return "Hook(" + std::to_string(getValue()) + ")";
}

void HookCard::play(Game& game, Player& player) {
	CardCollection& bank = player.getBank();

	if (bank.empty()) {
		std::cout << "Hook: No cards in the bank to play." << std::endl;
		return;
	}

	int highestValue = 0;

	for (int i = 1; i < (int)bank.size(); i++) {
		if (bank[i]->getValue() > bank[highestValue]->getValue()) {
			highestValue = i;
		}
	}
	Card* hookedCard = player.removeBankCard(highestValue);

	std::cout << "Hook: Played " << hookedCard->str() << " from the bank." << std::endl;
	player.addCardToPlayArea(hookedCard);

	if (player.isBust()) {
		std::cout << player.getName() << " busted after playing " << hookedCard->str() << "!" << std::endl;
	}

	hookedCard->play(game, player);
}

