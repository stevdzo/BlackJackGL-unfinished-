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
		"btn_play",
		vec2(window_width / 2, 300), 
		vec2(200, 50), 
		ButtonShape::RECTANGLE,
		[this]() { btn::play(*this); }));

	gui_->add_element(std::make_unique<Button>(
		"btn_quit",
		vec2(window_width / 2, 200),
		vec2(200, 50), 
		ButtonShape::RECTANGLE,
		[this]() { btn::quit(); }));

	gui_->add_element(std::make_unique<GUIText>(
		"txt_blackjack",
		vec2(window_width / 2, window_height-50),
		"BLACKJACK!!"));
	
}

void Game::init_running() {

	gui_ = std::make_unique<GUI>();

	gui_->add_element(std::make_unique<Button>(
		"btn_confirm",
		vec2(window_width/2., 75),
		vec2(200, 50),
		ButtonShape::RECTANGLE,
		[this]() { btn::deal(*this); }));

	gui_->add_element(std::make_unique<GUIText>(
		TXT_PLACE_BET,
		vec2(window_width / 2 - 150, window_height - 100),
		"Place Your Bets!"));

	gui_->add_element(std::make_unique<GUIText>(
		TXT_TOTAL_BET_LABEL,
		vec2(10, window_height - 50),
		"Total bet:"));

	gui_->add_element(std::make_unique<GUIText>(
		TXT_TOTAL_BET,
		vec2(175, window_height - 50),
		"0"));

	gui_->add_element(std::make_unique<GUIText>(
		TXT_PLAYER_HAND,
		vec2(250, 300),
		" "));

	gui_->add_element(std::make_unique<GUIText>(
		TXT_DEALER_HAND,
		vec2(550, 300),
		" "));

	for (size_t i = 0; i < 3; i++) {

		auto chip = std::make_unique<Chip>(
			"chip_500_" + (i+1),
			vec2(50, 50),
			vec2(50, 50),
			ButtonShape::CIRCLE,
			[] () {}
		);

		Chip& chip_ref = *chip;
		chip->set_callback([this, &chip_ref]() { btn::place_bet(*this, chip_ref); });

		gui_->add_element(std::move(chip));
	}

	deck_ = std::make_unique<Deck>();
	player_ = std::make_unique<Player>();
	dealer_ = std::make_unique<Player>();
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