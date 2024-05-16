#include "vec2.h"

vec2::vec2() : x_(0.0f), y_(0.0f) {
}

vec2::vec2(float p_x, float p_y) : x_(p_x), y_(p_y) {
}

const vec2 vec2::operator+(const vec2& p_v) {
    return vec2(x_ + p_v.x_, y_ + p_v.y_);
}

const vec2 vec2::operator-(const vec2& p_v) {
    return vec2(x_ - p_v.x_, y_ - p_v.y_);
}

const vec2 vec2::operator+(float p_s) {
    return vec2(x_ + p_s, y_ + p_s);
}

const vec2 vec2::operator-(float p_s) {
    return vec2(x_ - p_s, y_ - p_s);
}
