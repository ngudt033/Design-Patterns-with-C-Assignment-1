#include "OracleCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

OracleCard::OracleCard(int value) : Card(value, CardType::Oracle) {

}

std::string OracleCard::str() const {
	return "Oracle(" + std::to_string(getValue()) + ")";
}

void OracleCard::play(Game& game, Player& player) {
	if (game.getDeck().empty()) {
		std::cout << "Oracle: no cards left in the deck to peek at.";
		return;
	}

	Card* topCard = game.getDeck().back();
	std::cout << "Oracle: the top card of the deck is " << topCard->str() << std::endl;

}
