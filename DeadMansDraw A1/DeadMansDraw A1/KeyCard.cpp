#include "KeyCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

KeyCard::KeyCard(int value) : Card(value, CardType::Key) {

}

std::string KeyCard::str() const {
	return "Key(" + std::to_string(getValue()) + ")";
}

void KeyCard::play(Game& game, Player& player) {
}

void KeyCard::willAddToBank(Game& game, Player& player) {
	CardCollection& playArea = player.getPlayArea();
	bool hasChest = false;

	for (int i = 0; i < playArea.size(); ++i) {
		if (playArea[i]->type() == CardType::Key) {
			hasChest = true;
		}
	}
	if (hasChest) {
		std::cout << "Chest and Key bonus activated!" << std::endl;
	}
}