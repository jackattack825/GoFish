/*********************************************************************
** Program Filename: game.cpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains definitions for functions in game.hpp
*********************************************************************/
#include "card.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "game.hpp"
#include <string>
#include <iostream>


using namespace std;

/*********************************************************************
** Function: Game
** Description: constructor for game class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Game::Game() {
	this->cards.shuffle();
	Card c;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 7; j++) {
			//cout << "card is\n";
			c=this->cards.removeCard();
			//cout << "card to be dealt is" << endl;
			//c.getCard();
			this->players[i].addCard(c);
			//cout << "card added to hand was" << endl;
			//this->players[i].getHand().getCards().back().getCard();
		}
	}
}

/*********************************************************************
** Function: get winner
** Description: gets winner if there is one and returns -1 if game isnt over
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Game::getWinner() {
	int p1, p2;
	p1 = this->players[0].getNBooks();
	p2 = this->players[1].getNBooks();
	if (p1 + p2 !=13) {
		cout << "No winner yet\n" << endl;
		return -1;
	}

	if (p1 > p2)
		return 0;
	return 1;
}

/*********************************************************************
** Function: get cards
** Description: retruns deck
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Deck Game::getCards() {
	return this->cards;
}

/*********************************************************************
** Function: get player
** Description: gets player selected
** Parameters: index
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Player Game::getPlayer(int index) {
	return this->players[index];
}

/*********************************************************************
** Function: playerTurn
** Description: takes turn for player
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::playerTurn() {
	Card c;
	cout << "It is the human's turn" << endl;
	int numC = this->cards.getNumCards();
	if (numC == 0)
		cout << "Deck is empty\n";
	if (this->players[1].getHand().getNumCards() == 0 && numC != 0) {
		cout << "Out of cards, drawing a fresh one\n";
		c = this->cards.removeCard();
		this->players[0].addCard(c);
		cout << "Received the following card\n";
		c.getCard();
	}
	int rank = this->players[0].requestCards();
	

	int num = this->players[1].getHand().numOfRank(rank);

	cout << "\nOpponent has " << num << " card(s) of rank " << rank << " to give you\n";

	if (num == 0) {
		cout << "cpu didn't have any cards with the rank: " << rank << " Gofish!" << endl;
		c = this->cards.removeCard();
		cout << "You have drawn the following card:" << endl;
		c.getCard();
		this->players[0].addCard(c);
		if (c.getRank() == rank) {
			cout << "the rank matched your requested rank from earlier, go again" << endl;
			playerTurn();
		}
		else {
			cout << "Your turn is over. Time to check for books.\n" << endl;
			this->players[0].checkBooks();
			return;
		}
	}
	else {
		for (int j = 0; j < this->players[1].getHand().getNumCards(); j++) {
			if (this->players[1].getHand().getCards().at(j).getRank() == rank) {
				this->players[0].addCard(this->players[1].removeCard(j));	
				//j--;
			}
		}
		this->players[0].checkBooks();
	}
}

/*********************************************************************
** Function: cpuTurn
** Description: takes turn for cpu
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::cpuTurn() {
	cout << "It is the cpu's turn" << endl;
	Card c;
	int numC = this->cards.getNumCards();
	if (numC == 0)
		cout << "Deck is empty\n";
	if (this->players[1].getHand().getNumCards() == 0 && numC !=0) {
		cout << "Out of cards, drawing a fresh one\n";
		c = this->cards.removeCard();
		this->players[1].addCard(c);
		cout << "Received the following card\n";
		c.getCard();
	}
	int rank = this->players[1].cpuRequestCards();

	int num = this->players[0].getHand().numOfRank(rank);
	cout << "cpu wants cards with rank " << rank << endl;
	cout << "\nYou are giving " << num << " card(s) of rank " << rank << " to the bot\n";

	if (num == 0) {
		cout << "you didn't have any cards with the rank: " << rank << " Gofish!" << endl;
		c = this->cards.removeCard();
		cout << "Cpu has drawn their card" << endl;
		this->players[1].addCard(c);
		if (c.getRank() == rank) {
			cout << "the rank matched the cpu's requested rank from earlier, go again" << endl;
			cpuTurn();
		}
		else {
			cout << "Cpu's turn is over. Time to check for books.\n" << endl;
			this->players[1].checkBooks();
			return;
		}
	}
	else {
		for (int j = 0; j < this->players[0].getHand().getNumCards(); j++) {
			if (this->players[0].getHand().getCards().at(j).getRank() == rank) {
				this->players[1].addCard(this->players[0].removeCard(j));
				//j--;
			}
		}
		this->players[1].checkBooks();
	}
}

/*********************************************************************
** Function: endGame
** Description: displays info about game and winner
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::endGame(int winner) {
	if (winner == 1) {
		cout << "The cpu pwned u" << endl;
	}
	else {
		cout << "congrats you have won the game" << endl;
	}
}

/*********************************************************************
** Function: printScores
** Description: displays info about game
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Game::printScores() {
	cout << "You have made " << this->players[0].getNBooks() << " books this game\n";
	cout << "The cpu has made " << this->players[1].getNBooks() << " books this game\n";
}