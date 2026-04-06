 #include "Card.h"

Card::Card(int value, CardType typeValue) : value(value), typeValue(typeValue) {
}

Card::~Card() {
}

int Card::getValue() const {
	return value;
}

CardType Card::type() const {
	return typeValue;
}

void Card::willAddToBank(Game& game, Player& player) {
}