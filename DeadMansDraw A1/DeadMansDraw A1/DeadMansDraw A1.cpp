#include "Game.h"
#include "game_title.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	srand((unsigned)time(0));
	std::cout << GAME_TITLE << std::endl;
	Game game;
	game.startGame();
	return 0;
}