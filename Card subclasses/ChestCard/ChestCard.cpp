#include "ChestCard.h"
#include "Game.h"
#include "Player.h"

ChestCard::ChestCard(int value) : Card(value, CardType::Chest) {

}

std::string ChestCard::str() const {
	return "Chest(" + std::to_string(getValue()) + ")";
}

void ChestCard::play(Game& game, Player& player) {
}

void ChestCard::willAddToBank(Game& game, Player& player) {
}