#include "HookCard.h"
#include "Game.h"
#include "Player.h"

HookCard::HookCard(int value) : Card(value, CardType::Hook) {

}

std::string HookCard::str() const {
	return "Hook(" + std::to_string(getValue()) + ")";
}

void HookCard::play(Game& game, Player& player) {
}

