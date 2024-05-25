#include "Game.h"

Game::Game() {
	//current_game_state_ = std::make_unique<MenuGameState>();
	change_game_state(std::make_unique<MenuGameState>());
}

//void Game::init() {
//
//}

void Game::init_menu() {

	gui_ = std::make_unique<GUI>();

	gui_->add_element(std::make_unique<Button>(
		vec2(window_width / 2, 300), 
		vec2(200, 50), 
		ButtonShape::RECTANGLE,
		[this]() { btn::play(*this); }));

	gui_->add_element(std::make_unique<Button>(
		vec2(window_width / 2, 200),
		vec2(200, 50), 
		ButtonShape::RECTANGLE,
		[this]() { btn::quit(); }));

	gui_->add_element(std::make_unique<GUIText>(
		vec2(window_width / 2, window_height-50),
		"BLACKJACK!!"));
	
}

void Game::init_running() {

	gui_ = std::make_unique<GUI>();

	/*gui_->add_element(std::make_unique<Button>(
		vec2(200, 100),
		vec2(100, 100),
		ButtonShape::RECTANGLE,
		[this]() { btn::back(*this); }));*/

	gui_->add_element(std::make_unique<GUIText>(
		vec2(window_width / 2 - 150, window_height - 50),
		"Place Your Bets!"));

	for (size_t i = 0; i < 5; i++)
	{
		gui_->add_element(std::make_unique<Chip>(
			vec2(100, 100),
			vec2(50, 50),
			ButtonShape::CIRCLE,
			[this]() { btn::place_bet(*this); }));
	}

	for (size_t i = 0; i < 3; i++)
	{
		gui_->add_element(std::make_unique<Chip>(
			vec2(200, 100),
			vec2(50, 50),
			ButtonShape::CIRCLE,
			[this]() { btn::place_bet(*this); }));
	}


	deck_ = std::make_unique<Deck>();
	deck_->shuffle_deck();

	player_1_ = std::make_unique<Player>();
	//player_1_->set_hand_pos(vec2(player_1_pos_x, player_1_pos_y));
	//player_1_->add_card(deck_->draw_card());
	//player_1_->add_card(deck_->draw_card());

	player_2_ = std::make_unique<Player>();
	//player_2_->set_hand_pos(vec2(player_2_pos_x, player_2_pos_y));
	//player_2_->add_card(deck_->draw_card());
	//player_2_->add_card(deck_->draw_card());
}

void Game::change_game_state(std::unique_ptr<GameState> gs) {

	if (current_game_state_)
		current_game_state_->exit(*this);

	previous_game_state_ = std::move(current_game_state_);
	current_game_state_ = std::move(gs);

	current_game_state_->enter(*this);
}

void Game::update(float delta_time) { 
	current_game_state_->execute_update(*this, delta_time);
}

void Game::render() {
	current_game_state_->execute_render(*this);
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
	Input::instance().mouse(button, state, x, y);

	if (button == GLUT_LEFT)
		if (state == GLUT_UP)
			gui_->on_element_click(Input::instance().get_mouse_vector());
}