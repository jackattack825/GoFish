/*********************************************************************
** Program Filename: hand.cpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains definitions for functions in hand.h
*********************************************************************/
#include "card.hpp"
#include "hand.hpp"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

/*********************************************************************
** Function: Hand
** Description: constructor for hand class
** Parameters: cards and num_cards
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Hand::Hand(vector<Card> cards, int n_cards) {
	setHand(cards, n_cards);
}

/*********************************************************************
** Function: Hand
** Description: constructor for hand class
** Parameters: cards and num_cards
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Hand::Hand() {
	//this->cards.resize(7);
	this->n_cards = 0;
}

/*********************************************************************
** Function: setHand
** Description: sets properties for hand
** Parameters: cards and num cards
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Hand::setHand(vector<Card> cards, int n_cards) {
	this->cards = cards;
	this->n_cards = n_cards;
}


/*********************************************************************
** Function: getCards
** Description: gets cards
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
vector<Card>& Hand::getCards() {
	return this->cards;
}


/*********************************************************************
** Function: removeCard
** Description: removes card and fixes length
** Parameters: index
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Card Hand::removeCard(int index) {
	Card c = this->cards.at(index);
	this->cards.erase(this->cards.begin() + index);
	this->n_cards--;
	return c;
}

/*********************************************************************
** Function: addCard
** Description: adds card and fixes ength
** Parameters: card
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Hand::addCard(Card ca) {
	this->cards.push_back(ca);
	this->n_cards++;
}

/*********************************************************************
** Function: printHand
** Description: prints hand
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Hand::printHand() {
	Card c;
	for (int i = 0; i < this->n_cards; i++) {
		c=this->cards.at(i);
		c.getCard();
	}
}

/*********************************************************************
** Function: numOfRank
** Description: returns amount of requested card rank in hand
** Parameters: rank
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Hand::numOfRank(int rank) {
	int count = 0;;
	for (int i = 0; i < this->n_cards; i++) {
		if (this->cards.at(i).getRank() == rank)
			count++;
	}
	return count;
}

/*********************************************************************
** Function: getNumCards
** Description: returns num of cards
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Hand::getNumCards() {
	return this->n_cards;
}