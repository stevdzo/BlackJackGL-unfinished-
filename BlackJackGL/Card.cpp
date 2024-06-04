#include "Card.h"

Card::Card(Rank rank, Suit suit) : GameObject(), rank_(rank), suit_(suit), tex_(FRONT) {

}

void Card::set_value(int v) {
    value_ = v;
}

Rank Card::get_rank() const {
    return rank_;
}

Suit Card::get_suit() const {
    return suit_;
}

void Card::set_tex(Texture tex) {
    sprite_.set_tex(static_cast<int>(tex));
}

void Card::render() const {
    GameObject::render();
}
