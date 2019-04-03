/*********************************************************************
** Program Filename: player.cpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains definitions for functions in player.hpp
*********************************************************************/
#include "card.hpp"
#include "hand.hpp"
#include "player.hpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>


using namespace std;

/*********************************************************************
** Function: Player
** Description: constructor for player class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Player::Player() {
	this->n_books = 0;
	this->books = new int[13];
}

/*********************************************************************
** Function: ~Player
** Description: wipes memeory allocated
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Player::~Player() {
	delete[] this->books;
}

/*********************************************************************
** Function: getBooks
** Description: returns books
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int* Player::getBooks() {
	return this->books;
}

/*********************************************************************
** Function: getNBooks
** Description: returns number of books
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Player::getNBooks() {
	return this->n_books;
}

/*********************************************************************
** Function: addBook
** Description: add a book
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Player::addBook(int index) {
	this->books[index] = 1;
}

/*********************************************************************
** Function: requestCards
** Description: gets rank of card to request
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Player::requestCards() {
	cout << "Here are the ranks you can ask for from the other player" << endl;
	this->hand.printHand();
	int ans = 0;
	do {
		cout << "Choose a rank to request. It must be one that you already have." << endl;
		cin >> ans;
	} while (this->hand.numOfRank(ans) <= 0);

	return ans;
}

/*********************************************************************
** Function: cpurequestCards
** Description: gets rank of card to request
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Player::cpuRequestCards() {
	cout << "cpu is selecting a rank to get from you" << endl;
	int rank;
	srand(time(NULL));
	//do {
	rank = this->hand.getCards()[rand() % this->hand.getNumCards()].getRank();
	//} while (this->hand.numOfRank(ans) <= 0);

	return rank;
}

/*********************************************************************
** Function: get hand
** Description: gets hand
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Hand Player::getHand() {
	return this->hand;
}

void Player::addCard(Card c) {
	this->hand.addCard(c);
}

Card Player::removeCard(int index) {
	return this->hand.removeCard(index);
}

/*********************************************************************
** Function: checkBooks
** Description: gets hand
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Player::checkBooks() {
	cout << "checking books\n" << endl;
	int rank;
	int count;
	for (int i = 0; i < this->hand.getNumCards(); i++) {
		rank = this->hand.getCards()[i].getRank();
		count = this->hand.numOfRank(rank);
		if (count == 4) {
			this->books[i] = 1;
			this->n_books++;
			cout << "Made a book with rank of: " << rank << endl;
			for (int j = 0; j < this->hand.getNumCards(); j++) {
				if (this->hand.getCards()[j].getRank() == rank) {
					this->hand.removeCard(j);
				}
			}
		}
	}
}