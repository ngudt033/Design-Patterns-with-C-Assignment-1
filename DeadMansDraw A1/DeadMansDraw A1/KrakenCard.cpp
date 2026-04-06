#include "KrakenCard.h"
#include "Game.h"
#include "Player.h"

KrakenCard::KrakenCard(int value) : Card(value, CardType::Kraken) {

}

std::string KrakenCard::str() const {
	return "Kraken(" + std::to_string(getValue()) + ")";
}

void KrakenCard::play(Game& game, Player& player) {
}