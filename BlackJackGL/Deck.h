#ifndef DECK_H
#define DECK_H

#include "Globals.h"
#include "Card.h"

class Deck {

public:

	Deck();

	void shuffle_deck();
	std::unique_ptr<Card> draw_card();

	void render() const;

private:

	std::vector<std::unique_ptr<Card>> cards_;

};
#endif