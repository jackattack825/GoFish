/*********************************************************************
** Program Filename: player.hpp
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains player definition and prototypes
*********************************************************************/
#ifndef player
#define player

#include "card.hpp"
#include "hand.hpp"
class Player {

private:
	Hand hand;
	int* books;
	int n_books;

public:
	Player();
	~Player();

	int* getBooks();
	int getNBooks();
	void addBook(int);
	void addCard(Card c);
	Card removeCard(int index);

	Hand getHand();
	void checkBooks();

	int requestCards();
	int cpuRequestCards();
};
#endif