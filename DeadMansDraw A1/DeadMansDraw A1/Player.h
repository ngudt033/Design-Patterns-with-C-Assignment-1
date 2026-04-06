#pragma once
#include <string>
#include "Card.h"

class Game;

class Player {
private:
	std::string _name;
	CardCollection _playArea;
	CardCollection _bank;

public:
	Player();
	~Player();

	std::string getName() const;

	bool playCard(Card* card, Game& game);
	bool isBust() const;
	void bankCards(Game& game);

	void displayPlayArea() const;
	void displayBank() const;
	int calculateScore() const;
	void addCardToPlayArea(Card* card);

	CardCollection& getPlayArea();
	CardCollection& getBank();
	Card* removeBankCard(int index);
	

};