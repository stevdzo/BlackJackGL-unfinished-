#include "Input.h"

Input& Input::instance() {
	static Input instance;
	return instance;
}

void Input::mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		set_mouse_vector(vec2(x, (int)window_height - y));
	}
}

bool Input::is_mouse_key_pressed() const {
	return mouse_pressed_;
}

void Input::press_mouse_key() {
	mouse_pressed_ = true;
}

void Input::release_mouse_key() {
	mouse_pressed_ = false;
}

vec2 Input::get_mouse_vector() const {
	return mouse_;
}

void Input::ui_element_click() {
}

void Input::set_mouse_vector(vec2 mouse_vector) {
	mouse_.x_ = mouse_vector.x_;
	mouse_.y_ = mouse_vector.y_;
	press_mouse_key();
}

Input::Input() {
}