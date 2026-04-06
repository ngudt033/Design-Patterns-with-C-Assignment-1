#include "Player.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>

Player::Player() {
	std::string names[] = { "Sam", "Billy", "Jen", "ally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 9];
}

Player::~Player() {
}

std::string Player::getName() const {
	return _name;
}

bool Player::playCard(Card* card, Game& game) {
	_playArea.push_back(card);
	if (isBust()) {
		return true;
	}
	card->play(game, *this);
 	return false;
}

bool Player::isBust() const {
	for (int i = 0; i < (int)_playArea.size(); i++) {
		for (int j = i + 1; j < (int)_playArea.size(); j++) {
			if (_playArea[i]->type() == _playArea[j]->type()) {
				return true;
			}
		}
	}
	return false;
}

	void Player::bankCards(Game & game) {
		for (int i = 0; i < (int)_playArea.size(); i++) {
			_playArea[i]->willAddToBank(game, *this);
			_bank.push_back(_playArea[i]);
		}
		_playArea.clear();
	}

	void Player::displayPlayArea() const { 
		std::cout << "Play Area: " << std::endl;
		for (int i = 0; i < (int)_playArea.size(); i++) {
			std::cout << _playArea[i]->str() << std::endl;
		}
		std::cout << std::endl;
	}

	void Player::displayBank() const {
		std::cout << "Bank: " << std::endl;
		for (int i = 0; i < (int)_bank.size(); i++) {
			std::cout << _bank[i]->str() << std::endl;
		}
		std::cout << std::endl;
	}

	int Player::calculateScore() const {
		int cannonBest = 0;
		int chestBest = 0;
		int keyBest = 0;
		int swordBest = 0;
		int hookBest = 0;
		int oracleBest = 0;
		int mapBest = 0;
		int mermaidBest = 0;
		//int krakenBest = 0;

		for (int i = 0; i < (int)_bank.size(); i++) {
			CardType current = _bank[i]->type();
			int currentValue = _bank[i]->getValue();

			if (current == Cannon && currentValue > cannonBest) {
				cannonBest = currentValue;
			}
			else if (current == Chest && currentValue > chestBest) {
				chestBest = currentValue;
			}
			else if (current == Key && currentValue > keyBest) {
				keyBest = currentValue;
			}
			else if (current == Sword && currentValue > swordBest) {
				swordBest = currentValue;
			}
			else if (current == Hook && currentValue > hookBest) {
				hookBest = currentValue;
			}
			else if (current == Oracle && currentValue > oracleBest) {
				oracleBest = currentValue;
			}
			else if (current == Map && currentValue > mapBest) {
				mapBest = currentValue;
			}
			else if (current == Mermaid && currentValue > mermaidBest) {
				mermaidBest = currentValue;
			}
			//else if (current == Kraken && currentValue > krakenBest) {
				//krakenBest = currentValue;
			
	
		}
		int total = 0;
		total += cannonBest;
		total += chestBest;
		total += keyBest;
		total += swordBest;
		total += hookBest;
		total += oracleBest;
		total += mapBest;
		total += mermaidBest;
		//total += krakenBest;

		return total;

	}

	CardCollection& Player::getPlayArea() {
		return _playArea;
	}

	CardCollection& Player::getBank() {
		return _bank;
	}

	Card* Player::removeBankCard(int index) {
		if (index < 0 || index >= (int)_bank.size()) {
			return nullptr;
		}
		Card* card = _bank[index];
		_bank.erase(_bank.begin() + index);
		return card;
	}

	void Player::addCardToPlayArea(Card* card) {
		_playArea.push_back(card);
	}