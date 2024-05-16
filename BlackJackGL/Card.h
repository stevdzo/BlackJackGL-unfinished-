#ifndef CARD_H
#define CARD_H

#include "GameObject.h"

enum class Rank {
	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};

enum class Suit {
	CLUBS,	
	DIAMONDS,
	HEARTS,
	SPADES
};

class Card : public GameObject {

public:

	Card(Rank rank, Suit suit);

	Rank get_rank() const;
	Rank get_suit() const;

private:

	Rank rank_;
	Suit suit_;

};
#endif