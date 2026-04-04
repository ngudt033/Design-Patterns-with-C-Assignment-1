#include "Card.h"

Card::Card(int value, CardType type) : value(value), typeValue(type) {
}

Card::~Card() {
}

int Card::getValue() const {
	return value;
}

int Card::type() const {
	return typeValue;
}

void Card::willAddToBank(Game& game, Player& player) {
}