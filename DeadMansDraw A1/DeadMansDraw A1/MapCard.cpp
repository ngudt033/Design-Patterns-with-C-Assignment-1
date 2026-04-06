#include "MapCard.h"
#include "Game.h"
#include "Player.h"

MapCard::MapCard(int value) : Card(value, CardType::Map) {

}

std::string MapCard::str() const {
	return "Map(" + std::to_string(getValue()) + ")";
}

void MapCard::play(Game& game, Player& player) {
}


