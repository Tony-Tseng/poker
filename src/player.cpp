#include "player.hpp"

void Player::PushCards(std::vector<Card> cards)
{
    for(auto card: cards)
    {
        this->cards.push_back(card);
    }
    return;
}