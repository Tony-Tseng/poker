#pragma once
#include<vector>
#include"card.hpp"

class Board
{
private:
    std::vector<Card> cards;
public:
    Board(){};
    Board(std::vector<Card> cards): cards(cards) {};

    std::vector<Card> ShowCards(){ return this->cards; }
    void PushCards(std::vector<Card> cards);
    void PopCards(int num);
};

