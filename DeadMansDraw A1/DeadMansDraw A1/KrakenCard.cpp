#include "KrakenCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

KrakenCard::KrakenCard(int value) : Card(value, CardType::Kraken) {

}

std::string KrakenCard::str() const {
	return "Kraken(" + std::to_string(getValue()) + ")";
}

//void KrakenCard::play(Game& game, Player& player) {
//	std::cout << "Kraken draws 3 cards.";
//
//	for (int i = 0; i < 3, i++) {
//		Card* extraCard = game.drawCard();
//
//		if (extraCard == nullptr) {
//			std::cout << "No more cards to draw." << std::endl;
//			return;
//		}
//		else {
//			std::cout << "Kraken draws " << extraCard->str() << std::endl;
//			bool bust = player.playCard(extraCard, game);
//
//			if (bust) {
//				std::cout << player.getName() << " busted after drawing " << extraCard->str() << "!" << std::endl;
//				return;
//			}
//			
//		}
//	}
//}