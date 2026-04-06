#include "CannonCard.h"
#include "Game.h"
#include "Player.h"

CannonCard::CannonCard(int value) : Card(value, CardType::Cannon) {

}

std::string CannonCard::str() const {
	return "Cannon(" + std::to_string(getValue()) + ")";
}

void CannonCard::play(Game& game, Player& player) {
}