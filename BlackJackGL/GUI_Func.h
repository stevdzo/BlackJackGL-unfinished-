#ifndef GUI_FUNC_H
#define GUI_FUNC_H

#include "dbg.h"

class Game;
class Chip;

namespace btn {

	void play(Game& g);
	void back(Game& g);
	void menu(Game& g);
	void quit();

	void place_bet(Game& g, Chip& c);
	void deal(Game& g);
	void hit(Game& g);
	void stay(Game& g);
}
#endif