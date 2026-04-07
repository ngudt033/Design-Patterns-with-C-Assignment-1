#include "Game.h"
#include "CannonCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
//#include "KrakenCard.h"
#include <iostream>
#include <algorithm>
#include <random>

Game::Game() : _currentPlayer(0),_round(1), _turn(1) {
	_players[0] = new Player();
	_players[1] = new Player();


}

Game::~Game() {
	for (int i = 0; i < (int)_deck.size(); i++) {
		delete _deck[i];
	}

	for (int i = 0; i < (int)_discardPile.size(); i++) {
		delete _discardPile[i];
	}

	delete _players[0];
	delete _players[1];
}

void Game::startGame() {
	createDeck();
	shuffleDeck(_deck);
	std::cout << "Starting Dead Man's Draw++!" << std::endl;


	while (!_deck.empty()) {
		playTurn();
	}
	endGame();
}

void Game::createDeck() {

	for (int i = 2; i <= 7; i++) {
		_deck.push_back(new CannonCard(i));
		_deck.push_back(new ChestCard(i));
		_deck.push_back(new KeyCard(i));
		_deck.push_back(new SwordCard(i));
		_deck.push_back(new HookCard(i));
		_deck.push_back(new OracleCard(i));
		_deck.push_back(new MapCard(i));
		//_deck.push_back(new KrakenCard(i));
	}

	for (int i = 4; i <= 9; i++) {
		_deck.push_back(new MermaidCard(i));
	}
}

void Game::shuffleDeck(CardCollection & cards) {
	CardCollection shuffleDeck{ cards.begin(), cards.end() };
	std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
	std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

void Game::playTurn() {
	Player* currentPlayer = getCurrentPlayer();
	std::cout << std::endl;
	std::cout << "--- Round: " << _round << "," << "Turn: " << _turn << " ---" << std::endl;
	std::cout << currentPlayer->getName() <<"'s turn." << std::endl;
	std::cout << currentPlayer->getName() <<"'s Score: " << currentPlayer->calculateScore() << std::endl;

	bool keepDrawingCards = true;

	while (keepDrawingCards) {
		Card* drawnCard = drawCard();

		if (drawnCard == nullptr) {
			return;
		}

		std::cout << currentPlayer->getName() <<" draws a " << drawnCard->str() << std::endl;

		bool busted = currentPlayer->playCard(drawnCard, *this);

		if (busted || currentPlayer->isBust()) {

			std::cout << currentPlayer->getName() << " busted!" << std::endl;

			for (int i = 0; i < (int)currentPlayer->getPlayArea().size(); i++) {
				_discardPile.push_back(currentPlayer->getPlayArea()[i]);
			}

			currentPlayer->getPlayArea().clear();
			switchPlayer();
			return;
		}


		currentPlayer->displayPlayArea();
		
		std::string input;

		while (true) {
			std::cout << "Draw again (y/n): " << std::endl;
			std::cin >> input;

			if (input == "n" || input == "N") {
				currentPlayer->bankCards(*this);
				currentPlayer->displayBank();
				std::cout << currentPlayer->getName() << "'s Score: " << currentPlayer->calculateScore() << std::endl;
				std::cout << std::endl;

				switchPlayer();
				return;
			}
			else if (input == "y" || input == "Y") {
				std::cout << std::endl;
				std::cout << std::endl;
				break;
			}
			else {
				std::cout << "Invalid input. Please enter either Y/N." << std::endl;
			}
		}

		

		

	}
}


Card* Game::drawCard() {
	if (_deck.empty()) {
		std::cout << "Deck is empty. Unable draw a card." << std::endl;
		return nullptr;
	}
	Card* topCard = _deck.back();
		_deck.pop_back();
		return topCard;
}

void Game::switchPlayer() {
	if (_currentPlayer == 0) {
		_currentPlayer = 1;
	}
	else {
		_currentPlayer = 0;
	}
	_turn++;

	if (_turn % 2 == 1) {
		_round++;
	}
}

void Game::endGame() {
	int playerOneScore = _players[0]->calculateScore();
	int playerTwoScore = _players[1]->calculateScore();

	std::cout << _players[0]->getName() << " Score: " << playerOneScore << std::endl;
	std::cout << _players[1]->getName() << " Score: " << playerTwoScore << std::endl;

	if (playerOneScore > playerTwoScore) {
		std::cout << _players[0]->getName() << " wins!" << std::endl;
	}
	else if (playerTwoScore > playerOneScore) {
		std::cout << _players[1]->getName() << " wins!" << std::endl;
	}
	else {
		std::cout << "It's a tie!, play again to determine the victor!" << std::endl;
	}

}

Player* Game::getCurrentPlayer() const {
	return _players[_currentPlayer];
}

Player* Game::getOtherPlayer() const {
	if (_currentPlayer == 0) {
		return _players[1];
	}
	else {
		return _players[0];
	}
}

CardCollection& Game::getDeck() {
	return _deck;
}

CardCollection& Game::getDiscardPile() {
	return _discardPile;
}
