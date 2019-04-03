/*********************************************************************
** Program Filename: game.hpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains player definition and prototypes
*********************************************************************/
#ifndef game_
#define game_

#include "card.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "deck.hpp"

class Game {

private:
	Deck cards;
	Player players[2];

public:
	Game();

	void playerTurn();
	void cpuTurn();
	int getWinner();
	void printScores();

	void endGame(int winner);

	Deck getCards();
	Player getPlayer(int index);

};
#endif