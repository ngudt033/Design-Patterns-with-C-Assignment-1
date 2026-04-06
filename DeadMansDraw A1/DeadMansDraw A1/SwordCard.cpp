#include "SwordCard.h"
#include "Game.h"
#include "Player.h"

SwordCard::SwordCard(int value) : Card(value, CardType::Sword) {

}

std::string SwordCard::str() const {
	return "Sword(" + std::to_string(getValue()) + ")";
}

void SwordCard::play(Game& game, Player& player) {
}
