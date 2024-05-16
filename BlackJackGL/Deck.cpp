#include "Deck.h"
#include <sstream>

Deck::Deck() {

    int index = 0;
    for (int suit = CLUBS; suit <= SPADES; ++suit) {
        for (int rank = ACE; rank <= KING; ++rank) {
           
            Card card 
            {  
                static_cast<Rank>(rank),
                static_cast<Suit>(suit) 
            };

            std::stringstream str_suit;

            switch (suit) {
            
            case CLUBS:
                str_suit << "clubs";
                break;
            case DIAMONDS:
                str_suit << "diamonds";
                break;
            case HEARTS:
                str_suit << "hearts";
                break;
            case SPADES:
                str_suit << "spades";
                break;
            }

            std::stringstream str_rank;

            rank < 11 ? str_rank << rank :
                        str_rank << rank + 1;
        
            std::string path = "res\\cards\\" + str_rank.str() + "_of_" + str_suit.str() + ".png";           
            card.add_sprite(path.c_str());

            card.set_pos(vec2(100, window_height/2));
            card.set_size(vec2(500.0f/3, 725.0f/3));

            cards_.push_back(std::make_unique<Card>(card));

            //std::cout << "INDEX: " << index << std::endl;

            index++;
        }
    }
}

void Deck::shuffle_deck() {
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cards_.begin(), cards_.end(), g);
}

std::unique_ptr<Card> Deck::draw_card() {
    if (cards_.empty())
        return nullptr;

    std::unique_ptr<Card> card = std::move(cards_.back());
    cards_.pop_back();

    return card;
}

void Deck::render() const {
    for (auto& card : cards_) {
        card->render();
    }
}