#include "GameObject.h"

GameObject::GameObject() : pos_(vec2()), size_(vec2()) {
}

void GameObject::set_pos(vec2 v) {
	pos_ = v;
}

void GameObject::set_size(vec2 v) {
	size_ = v;
}

void GameObject::add_sprite(const char* path) {
	sprite_.load_texture(path);
}