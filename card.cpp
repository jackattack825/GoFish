/*********************************************************************
** Program Filename: card.cpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains definitions for functions in card.h
*********************************************************************/
#include "card.hpp"
#include <string>
#include <iostream>


using namespace std;

/*********************************************************************
** Function: Card
** Description: constructor for card class
** Parameters: rank and suit
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Card::Card(int r, int s) : rank(r), suit(s){

}

/*********************************************************************
** Function: Card
** Description: constructor for card class
** Parameters: rank and suit
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Card::Card() {
	this->rank = -1;
	this->suit = 0;
}

/*********************************************************************
** Function: setCard
** Description: sets properties for card
** Parameters: rank and suit
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Card::setCard(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
}

/*********************************************************************
** Function: setRank
** Description: sets rank for card
** Parameters: rank
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Card::setRank(int rank) {
	this->rank = rank;
}

/*********************************************************************
** Function: setSuit
** Description: sets suit ofr card
** Parameters: suit
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Card::setSuit(int suit) {
	this->suit = suit;
}

/*********************************************************************
** Function: getRank
** Description: gets rank
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Card::getRank() {
	return this->rank;
}

/*********************************************************************
** Function: getSuit
** Description: gets suit
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Card::getSuit() {
	string x;
	switch (this->suit) {
	case 0:
		x = "spades";
		break;
	case 1:
		x = "diamonds";
		break;
	case 2:
		x = "hearts";
		break;
	case 3:
		x = "clubs";
		break;
	}
	cout << x << endl;
}

/*********************************************************************
** Function: getCard
** Description: prints a cards info
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Card::getCard() {
	string x;
	switch (this->suit) {
	case 0:
		x = "spades";
		break;
	case 1:
		x = "diamonds";
		break;
	case 2:
		x = "hearts";
		break;
	case 3:
		x = "clubs";
		break;
	}
	cout << "Card is of rank: " << this->rank << " and of suit: " << x << endl;
}