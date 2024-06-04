#include "Sprite.h"

Sprite::Sprite() : texture_(0) {
}

int Sprite::get_texture() const {
    return texture_;
}

std::vector<int> Sprite::get_textures() const {
    return textures_;
}

void Sprite::set_tex(int index) {
    texture_ = textures_[index];
}

void Sprite::load_texture(const char* p_path) {
    //texture_ = ::load_texture(p_path);
    textures_.push_back(::load_texture(p_path));
    set_tex(0);
}

void Sprite::render(float p_x, float p_y, float p_w, float p_h) const {
    texture_ ?
        ::render_sprite(texture_, p_x, p_y, p_w, p_h) :
        ::render_fill_rectangle(p_x, p_y, p_w, p_h, 1.0, 0.5, 0.2);
        
}