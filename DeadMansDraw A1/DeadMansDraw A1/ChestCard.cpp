#include "ChestCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

ChestCard::ChestCard(int value) : Card(value, CardType::Chest) {

}

std::string ChestCard::str() const {
	return "Chest(" + std::to_string(getValue()) + ")";
}

void ChestCard::play(Game& game, Player& player) {
}

void ChestCard::willAddToBank(Game& game, Player& player) {
	CardCollection& playArea = player.getPlayArea();
	bool hasKey = false;

	for (int i = 0; i < playArea.size(); ++i) {
		if (playArea[i]->type() == CardType::Key) {
			hasKey = true;
		}
	}
	if (hasKey) {
		std::cout << "Chest and Key bonus activated!" << std::endl;
	}
	else {
		return;
	}

	int bonusCardsDraw = (int)playArea.size();

	for (int i = 0; i < bonusCardsDraw; i++) {
		if (game.getDiscardPile().empty()) {
			std::cout << "No more cards to draw for Chest and Key bonus." << std::endl;
			return;
		}
		else {
			Card* bonusCard = game.getDiscardPile().back();
			game.getDiscardPile().pop_back();
			player.getBank().push_back(bonusCard);
			std::cout << "Chest and Key bonus: Drew " << bonusCard->str() << std::endl;
			
	}

}