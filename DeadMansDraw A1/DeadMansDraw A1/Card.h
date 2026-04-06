#pragma once
#include <string>
#include <vector>

class Game;
class Player;

enum CardType {
	Cannon,
	Chest,
	Key,
	Sword,
	Hook,
	Oracle,
	Map,
	Mermaid,
	Kraken,
};

class Card { 
private:
	int value;
	CardType typeValue;

public:
	Card(int value, CardType typeValue);
	virtual ~Card();

	int getValue() const;
	CardType type() const;

	virtual std::string str() const = 0;
	virtual void play(Game& game, Player& player) = 0;
	virtual void willAddToBank(Game& game, Player& player);
};

typedef std::vector<Card*> CardCollection;