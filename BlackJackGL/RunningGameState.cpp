#include "RunningGameState.h"
#include "Game.h"

void RunningGameState::enter(Game& g) {
	std::cout << "Entering RunningGameState" << std::endl;

	g.init_running();
}

void RunningGameState::execute_render(Game& g) {
	//std::cout << "Executing RunningGameState" << std::endl;
	g.player_->render();
	g.dealer_->render();
	g.gui_->render();
}

void RunningGameState::execute_update(Game& g, float delta_time) {
	
}

void RunningGameState::exit(Game& g) {
	std::cout << "Exiting RunningGameState" << std::endl;
}