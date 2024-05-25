#ifndef RUNNING_GAME_STATE_H
#define RUNNING_GAME_STATE_H

#include "GameState.h"

class RunningGameState : public GameState {

public:

	void enter(Game& g) override;
	void execute_render(Game& g) override;
	void execute_update(Game& g, float delta_time) override;
	void exit(Game& g) override;
};
#endif