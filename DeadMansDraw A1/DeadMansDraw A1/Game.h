#pragma once
#include "Player.h"

class Game {
private:
	CardCollection _deck;
	CardCollection _discardPile;
	Player* _players[2];
	int _currentPlayer;
	int _round;
	int _turn;

public: 
	Game();
	~Game();

	void startGame();
	void createDeck();
	void shuffleDeck();
	void playTurn();
	Card * drawCard();
	void switchPlayer();
	void endGame();
	
	Player* getCurrentPlayer() const;
	Player* getOtherPlayer() const;

	CardCollection& getDeck();
	CardCollection& getDiscardPile();  

};