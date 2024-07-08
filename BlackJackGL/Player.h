#ifndef PLAYER_H
#define PLAYER_H

#include "Globals.h"
#include "Card.h"

class Player {

public:

	Player();

	void add_card(std::unique_ptr<Card> card, bool flipped=false);
	int get_hand_value();

	void set_hand_pos(vec2);

	void render() const;

	void add_value(int v);

	int get_value() const;
	void set_value(int);

	void reveal_card();

private:

	std::vector<std::unique_ptr<Card>> hand_;
	vec2 hand_pos_;
	int value_;

};
#endif
