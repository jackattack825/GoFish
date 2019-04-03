/*********************************************************************
** Program Filename: deck.h
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains deck definition and prototypes
*********************************************************************/
#ifndef deck
#define deck

#include "card.hpp"
#include <vector>
class Deck {

private:
	vector<Card> cards;
	int n_cards;

public:
	Deck();
	void shuffle();

	vector<Card> getCards();
	int getNumCards();
	Card removeCard();
};
#endif