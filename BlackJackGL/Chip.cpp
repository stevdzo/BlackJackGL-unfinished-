#include "Chip.h"

Chip::Chip() : Button() {
}

Chip::Chip(vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback) : Button(pos, size, shape, callback) {

}

void Chip::click() {
	if (callback_)
		callback_();


}

void Chip::render() const {
	::render_circle(pos_.x_, pos_.y_, size_.x_, 0.2f, 0.4f, 1.0f);
}
