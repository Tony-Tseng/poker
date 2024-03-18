#include "Board.hpp"

void Board::PushCards(std::vector<Card> cards)
{
    for(auto card: cards)
    {
        this->cards.push_back(card);
    }
    return;
}

void Board::PopCards(int num) 
{
    for(int i=0;i<num;i++) 
    {
        this->cards.pop_back();
    }
}