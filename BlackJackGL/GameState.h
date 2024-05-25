#ifndef GAME_STATE_H
#define GAME_STATE_H

class Game;

class GameState {

public:

	virtual void enter(Game& g) = 0;
	virtual void execute_render(Game& g) = 0;
	virtual void execute_update(Game& g, float delta_time) = 0;
	virtual void exit(Game& g) = 0;
};
#endif