#include "MapCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

MapCard::MapCard(int value) : Card(value, CardType::Map) {

}

std::string MapCard::str() const {
	return "Map(" + std::to_string(getValue()) + ")";
}

void MapCard::play(Game& game, Player& player) {
	CardCollection drawnCards;

	for (int i = 0; i < 3; i++) {
		if (game.getDiscardPile().empty()) {
			return;
		}
		Card* drawnCard = game.getDiscardPile().back();
		game.getDiscardPile().pop_back();
		drawnCards.push_back(drawnCard);
	}

	if (drawnCards.empty()) {
		std::cout << "Map: no cards in the discard pile to draw." << std::endl;
		return;
	}
	
	std::cout << "Map: drawn cards from discard pile: ";
	for (int i = 0; i < (int)drawnCards.size(); i++) {
		std::cout << drawnCards[i]->str() << " ";
	}

	int chosenIndex = 0;

	for (int i = 1; i < (int)drawnCards.size(); i++) {
		if (drawnCards[i]->getValue() > drawnCards[chosenIndex]->getValue()) {
			chosenIndex = i;
		}
	}

	Card* chosenCard = drawnCards[chosenIndex];

	std::cout << "Map played: " << chosenCard->str() << " added to play area." << std::endl;
	
	player.addCardToPlayArea(chosenCard);

	for (int i = 0; i < (int)drawnCards.size(); i++) {
		if (i != chosenIndex) {
			game.getDiscardPile().push_back(drawnCards[i]);
		}
	}

	if (player.isBust()) {
		std::cout << player.getName() << " busted after playing " << chosenCard->str() << "!" << std::endl;
		return;
	}

	chosenCard->play(game, player);
}


