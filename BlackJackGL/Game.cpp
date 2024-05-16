#include "Game.h"

void Game::init() {

	deck_ = std::make_unique<Deck>();	
	deck_->shuffle_deck();

	player_1_ = std::make_unique<Player>();
	player_1_->set_hand_pos(vec2(player_1_pos_x, player_1_pos_y));
	player_1_->add_card(deck_->draw_card());
	player_1_->add_card(deck_->draw_card());

	player_2_ = std::make_unique<Player>();
	player_2_->set_hand_pos(vec2(player_2_pos_x, player_2_pos_y));
	player_2_->add_card(deck_->draw_card());
	player_2_->add_card(deck_->draw_card());
}

void Game::update(float delta_time) {
}

void Game::render() const {
	//deck_->render();
	player_1_->render();
	player_2_->render();
}

void Game::reshape(int w, int h) {
	glViewport(0, 0, (int)window_width, (int)window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, window_width, 0.0f, window_height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Game::display(void) {
	render();
}

void Game::idle(void) {
	update(1);
}

void Game::mouse(unsigned int button, int state, int x, int y) {
	/*if (button == GLUT_LEFT)
		if (state == GLUT_UP)
			player_1_->add_card(deck_->draw_card());*/
}