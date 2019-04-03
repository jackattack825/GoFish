/*********************************************************************
** Program Filename: main.cpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: runs gofish
*********************************************************************/
#include "card.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "game.hpp"
#include <string>
#include <iostream>


using namespace std;

//TODO player running out of cards, cards not being dealt

int main() {
	cout << "\n\nWelcome to GoFish.\nYou will start with 7 cards from the deck and then take turns with the cpu choosing a card of yours in hopes that they will have it.\nIf they do have any of the cards with the rank you chose they have to give them to you.\nThe goal is to get 4 of each rank. When this happens you make those cards a book and they are removed from the game.\nThe winner is the player with the most books when every book has been laid down.\nGood Luck!" << endl;
	cout << "\n\n";
	Game g;
	while (g.getWinner() == -1) {
		cout << "\n\n";
		g.playerTurn();
		g.cpuTurn();
		g.printScores();
	}
	g.endGame(g.getWinner());
	return 1;
}
