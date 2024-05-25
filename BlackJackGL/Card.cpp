#include "Card.h"

Card::Card(Rank rank, Suit suit) : GameObject(), rank_(rank), suit_(suit) {

}

Rank Card::get_rank() const {
    return Rank();
}

Rank Card::get_suit() const {
    return Rank();
}

void Card::render() const {
    GameObject::render();
}
