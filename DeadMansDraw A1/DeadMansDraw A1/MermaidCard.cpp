#include "MermaidCard.h"
#include "Game.h"
#include "Player.h"

MermaidCard::MermaidCard(int value) : Card(value, CardType::Mermaid) {

}

std::string MermaidCard::str() const {
	return "Mermaid(" + std::to_string(getValue()) + ")";
}

void MermaidCard::play(Game& game, Player& player) {

}