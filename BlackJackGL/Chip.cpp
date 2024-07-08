#include "Chip.h"

Chip::Chip() : Button() {
}

Chip::Chip(std::string tag, vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback, bool visible, bool enabled) : Button(tag, pos, size, shape, callback, visible, enabled), value_(500) {

}

void Chip::click() {
	if (callback_)
		callback_();
}

int Chip::get_value() const {
	return value_;
}

void Chip::render() const {
	::render_circle(pos_.x_, pos_.y_, size_.x_, 0.2f, 0.4f, 1.0f);
}
