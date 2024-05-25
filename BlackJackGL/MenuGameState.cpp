#include "MenuGameState.h"
#include "Game.h"

void MenuGameState::enter(Game& g) {
	std::cout << "Entering MainGameState" << std::endl;
	g.init_menu();
}

void MenuGameState::execute_render(Game& g) {
	//std::cout << "Executing MainGameState" << std::endl;
	g.gui_->render();
}

void MenuGameState::execute_update(Game& g, float delta_time) {

}

void MenuGameState::exit(Game& g) {
	std::cout << "Exiting MainGameState" << std::endl;
}