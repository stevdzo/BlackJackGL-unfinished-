#include "Button.h"

Button::Button() : GUIElement() {

}

Button::Button(vec2 pos, vec2 size, ButtonShape shape, std::function<void()> callback) : GUIElement(pos, size), shape_(shape), callback_(callback) {

}

ButtonShape Button::get_shape() const {
	return shape_;
}

void Button::click() {
	if (callback_)
		callback_();
}

void Button::render() const {
	GameObject::render();
}