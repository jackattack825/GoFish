/*********************************************************************
** Program Filename: deck.cpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains definitions for functions in deck.h
*********************************************************************/
#include "card.hpp"
#include "hand.hpp"
#include "deck.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

/*********************************************************************
** Function: Deck
** Description: constructor for deck class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Deck::Deck() {
	cout << "deck created\n" << endl;
	//this->cards.resize(52);
	int i = 0;
	Card c;
	for (int suit = 0; suit < 4; suit++) {
		for (int rank = 0; rank <= 12; rank++) {
			c= Card(rank, suit);
			//c.getCard();
			this->cards.push_back(c);
		}
	}
	this->n_cards = 52;
}

/*********************************************************************
** Function: getCards
** Description: gets cards
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
vector<Card> Deck::getCards() {
	return this->cards;
}

/*********************************************************************
** Function: getNumCards
** Description: gets num cards
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
int Deck::getNumCards() {
	return this->n_cards;
}

/*********************************************************************
** Function: removeCard
** Description: removes first non blank card to give to player
** Parameters: index
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
Card Deck::removeCard() {
	Card c=this->cards.front();
	this->cards.erase(this->cards.begin());
	return c;
}

/*********************************************************************
** Function: shuffle
** Description: shuffles cards
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void Deck::shuffle() {
	cout << "shuffling deck\n" << endl;
	srand(time(NULL));
	int x, y;
	Card temp;
	for (int i = 0; i < this->n_cards; i++) {
		x = rand() % this->n_cards;
		y = rand() % this->n_cards;
		temp = this->cards.at(x);
		this->cards.at(x) = this->cards.at(y);
		this->cards.at(y) = temp;
	}

}
