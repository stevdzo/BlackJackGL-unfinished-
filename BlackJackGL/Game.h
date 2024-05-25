#ifndef GAME_H
#define GAME_H

#include "Globals.h"
#include "Deck.h"
#include "Player.h"
#include "GUI.h"
#include "GUI_Func.h"
#include "GUIText.h"
#include "Input.h"
#include "Chip.h"

#include "GameState.h"
#include "MenuGameState.h"
#include "RunningGameState.h"

class Game {

public:

	Game();

	void init();
	void init_menu();
	void init_running();

	void change_game_state(std::unique_ptr<GameState> gs);

	void update(float delta_time);
	void render();

	void reshape(int w, int h);
	void display(void);
	void idle(void);
	void mouse(unsigned int button, int state, int x, int y);

public:

	std::unique_ptr<GameState> current_game_state_;
	std::unique_ptr<GameState> previous_game_state_;

	std::unique_ptr<Deck> deck_;
	std::unique_ptr<Player> player_1_;
	std::unique_ptr<Player> player_2_;

	std::unique_ptr<GUI> gui_;
};
#endif