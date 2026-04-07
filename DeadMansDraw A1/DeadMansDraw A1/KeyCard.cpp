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
}