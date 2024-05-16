#include "Sprite.h"

Sprite::Sprite() : texture_(0) {
}

int Sprite::get_texture() const {
    return texture_;
}

void Sprite::load_texture(const char* p_path) {
    texture_ = ::load_texture(p_path);
}

void Sprite::render(float p_x, float p_y, float p_w, float p_h) const {
    ::render_sprite(texture_, p_x, p_y, p_w, p_h);
}