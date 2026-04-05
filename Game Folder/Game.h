#pragma once
#include "Player.h"

class Game {
private:
	CardCollection deck;
	CardCollection discardPile;
	Player* players[2];
	int currentPlayer;
	int round;
	int turn;

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