#include "Button.h"

Button::Button() : GUIElement() {

}

Button::Button(std::string tag, vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback, bool visible, bool enabled) : GUIElement(tag, pos, size, visible), shape_(shape), enabled_(enabled), callback_(callback) {

}

ButtonShape Button::get_shape() const {
	return shape_;
}

void Button::enabled(bool en) {
	enabled_ = en;
}

bool Button::enabled(void) {
	return enabled_;
}

void Button::click() {
	if (callback_ && enabled_)
		callback_();
}

void Button::set_callback(std::function<void()> c) {
	callback_ = c;
}

void Button::render() const {
	GameObject::render();
}