#include "GUI_Func.h"
#include "Game.h"
#include "Update_Func.h"
#include <thread>

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

	void place_bet(Game& g, Chip& c) {

		if (!c.enabled()) return;

		std::cout << "Value: " << c.get_value() << '\n';

		::move_chip(c, vec2(100, 500), 0.0f);
		g.player_->add_value(c.get_value());
		g.gui_->update_text(TXT_TOTAL_BET, g.player_->get_value());	

		c.enabled(false);
	}

	void deal(Game& g) {
		
		g.deck_->shuffle_deck();

		g.player_->set_hand_pos(vec2(player_1_pos_x, player_1_pos_y));
		g.player_->add_card(g.deck_->draw_card());
		g.player_->add_card(g.deck_->draw_card());

		g.dealer_->set_hand_pos(vec2(player_2_pos_x, player_2_pos_y));
		g.dealer_->add_card(g.deck_->draw_card(), true);
		g.dealer_->add_card(g.deck_->draw_card());

		g.gui_->update_text(TXT_PLAYER_HAND, g.player_->get_hand_value());
		g.gui_->update_text(TXT_DEALER_HAND, 0);

		auto btn = g.gui_->get_element_by_tag<Button>(BTN_DEAL);	
		if (!btn) return;
		g.gui_->disable_button(*btn);	

		btn = g.gui_->get_element_by_tag<Button>(BTN_HIT);
		if (!btn) return;
		g.gui_->enable_button(*btn);

		btn = g.gui_->get_element_by_tag<Button>(BTN_STAY);
		if (!btn) return;
		g.gui_->enable_button(*btn);
	}

	void hit(Game& g) {
		dbg::print("Hitting");

		g.player_->add_card(g.deck_->draw_card());
		g.dealer_->reveal_card();

		g.gui_->update_text(TXT_PLAYER_HAND, g.player_->get_hand_value());
		g.gui_->update_text(TXT_DEALER_HAND, g.dealer_->get_hand_value());

		auto btn = g.gui_->get_element_by_tag<Button>(BTN_HIT);
		g.gui_->disable_button(*btn);

		dbg::print("1");

		//Sleep(1000);

		dbg::print("2");
	}

	void stay(Game& g) {
		dbg::print("Staying");

		g.dealer_->reveal_card();
		g.gui_->update_text(TXT_DEALER_HAND, g.dealer_->get_hand_value());

		auto btn = g.gui_->get_element_by_tag<Button>(BTN_STAY);
		g.gui_->disable_button(*btn);
	}
}