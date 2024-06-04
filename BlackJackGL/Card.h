#ifndef CARD_H
#define CARD_H

#include "GameObject.h"

enum Rank {
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

enum Suit {
	CLUBS = 1,	
	DIAMONDS,
	HEARTS,
	SPADES
};

enum Texture {
	FRONT = 0,
	BACK
};

class Card : public GameObject {

public:

	Card(Rank rank, Suit suit);

	~Card() override = default;

	void set_value(int);

	Rank get_rank() const;
	Suit get_suit() const;

	void set_tex(Texture tex);

	void render() const override;

private:

	int value_;

	Rank rank_;
	Suit suit_;
	Texture tex_;
};
#endif