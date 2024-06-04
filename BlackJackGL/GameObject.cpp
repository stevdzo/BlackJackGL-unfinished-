#include "GameObject.h"

GameObject::GameObject() : tag_("unnamed"), pos_(vec2()), size_(vec2()), sprite_(Sprite()) {
}

GameObject::GameObject(std::string tag, vec2 pos, vec2 size) : tag_(tag), pos_(pos), size_(size), sprite_(Sprite()) {
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

std::string GameObject::get_tag() const {
	return tag_;
}

vec2 GameObject::get_pos() const {
	return pos_;
}

vec2 GameObject::get_size() const{
	return size_;
}

void GameObject::render() const {
	sprite_.render(pos_.x_, pos_.y_, size_.x_, size_.y_);
}

void GameObject::update(float delta_time) {
	//pos_ = pos_ + delta_time*10;
}