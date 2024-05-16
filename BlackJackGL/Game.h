#ifndef GAME_H
#define GAME_H

#include "Globals.h"
#include "Deck.h"
#include "Player.h"

class Game {

public:

	void init();
	void update(float delta_time);
	void render() const;

	void reshape(int w, int h);
	void display(void);
	void idle(void);
	void mouse(unsigned int button, int state, int x, int y);

private:

	std::unique_ptr<Deck> deck_;
	std::unique_ptr<Player> player_1_;
	std::unique_ptr<Player> player_2_;

};
#endif