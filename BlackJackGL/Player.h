#ifndef PLAYER_H
#define PLAYER_H

#include "Globals.h"
#include "Card.h"

class Player {

public:

	Player();

	void add_card(std::unique_ptr<Card> card);
	int get_hand_value();

	void set_hand_pos(vec2);

	void render() const;

private:

	std::vector<std::unique_ptr<Card>> hand_;
	vec2 hand_pos_;

};
#endif
