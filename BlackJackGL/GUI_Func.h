#ifndef GUI_FUNC_H
#define GUI_FUNC_H

class Game;

namespace btn {

	void play(Game& g);
	void back(Game& g);
	void menu(Game& g);
	void quit();

	void place_bet(Game& g);
	void hit();

}


#endif