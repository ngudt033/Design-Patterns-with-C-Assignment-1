#pragma once
#include <string>
#include "Card.h"

class Game;

class Player {
private:
	std::string name;
	CardCollection playArea;
	CardCollection bank;

public:
	Player(std::string name);
	~Player();

	std::string getName() const;

	bool playCard(Card* card, Game& game);
	bool isBust() const;
	void bankCards(Game& game);

	void displayPlayArea() const;
	void displayBank() const;
	int calculateScore() const;

	CardCollection& getPlayArea();
	CardCollection& getBank();


};