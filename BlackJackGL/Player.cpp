#include "Player.h"

Player::Player() {
}

void Player::add_card(std::unique_ptr<Card> card, bool flipped) {

	//card->set_pos(vec2(500, 100));

	int hand_size = hand_.size();
	card->set_pos(vec2(hand_pos_.x_ + hand_size * 40 , hand_pos_.y_));

	if (flipped) {
		card->set_tex(BACK);
	}

	hand_.push_back(std::move(card));
}

int Player::get_hand_value() {

	int value = 0;
	int aces = 0;

	for (const auto& card : hand_) {

		int card_val = static_cast<int>(card->get_rank());

		if (card_val >= 10)
			card_val = 10;
		else if (card_val == ACE) {
			aces++;
			card_val = 11;
		}
		value += card_val;
	}

	while (value > 21 && aces > 0) {
		value -= 10;
		aces--;
	}
	return value;
}

void Player::set_hand_pos(vec2 v) {
	hand_pos_ = v;
}

void Player::render() const {
	for (auto& card : hand_) {
		card->render();
	}
}

void Player::add_value(int v) {
	value_ += v;
}

int Player::get_value() const {
	return value_;
}

void Player::set_value(int v) {
	value_ = v;
}

void Player::reveal_card() {
	hand_[0]->set_tex(FRONT);
}