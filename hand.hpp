/*********************************************************************
** Program Filename: hand.h
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains hand definition and prototypes
*********************************************************************/
#ifndef hande
#define hande

#include "card.hpp"
#include <vector>

using namespace std;
class Hand {

private:
	vector<Card> cards;
	int n_cards;

public:
	Hand(vector<Card> cards, int n_cards);
	Hand();
	void setHand(vector<Card> cards, int n_cards);

	vector<Card>& getCards();
	int getNumCards();
	Card removeCard(int index);
	void addCard(Card c);
	void printHand();

	int numOfRank(int rank);
};

#endif