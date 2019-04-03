/*********************************************************************
** Program Filename: card.h
** Author: Jackson Perry
** Date: 1/24/19
** Description: Contains card definition and prototypes
*********************************************************************/
#ifndef card
#define card

class Card {

private:
	int rank;
	int suit;

public:
	Card(int, int);
	Card();

	void setRank(int rank);
	void setSuit(int suit);
	void setCard(int rank, int suit);

	int getRank();
	void getSuit();
	void getCard();
};
#endif