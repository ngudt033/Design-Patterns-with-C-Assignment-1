#include "OracleCard.h"
#include "Game.h"
#include "Player.h"

OracleCard::OracleCard(int value) : Card(value, CardType::Oracle) {

}

std::string OracleCard::str() const {
	return "Oracle(" + std::to_string(getValue()) + ")";
}

void OracleCard::play(Game& game, Player& player) {
}
