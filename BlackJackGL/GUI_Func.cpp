#include "GUI_Func.h"
#include "Game.h"

namespace btn {
	
	void play(Game& g) {
		g.change_game_state(std::make_unique<RunningGameState>());
	}

	void back(Game& g) {
		g.change_game_state(std::move(g.previous_game_state_));
	}

	void menu(Game& g) {
		g.change_game_state(std::make_unique<MenuGameState>());
	}

	void quit() {
		exit(0);
	}

	void place_bet(Game& g) {
		
	}
}
