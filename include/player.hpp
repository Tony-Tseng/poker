#pragma once
#include<string>
#include<vector>
#include<iostream>

#include "card.hpp"
// #include "display.hpp"

class Player
{
private:
    std::vector<Card> cards;
public:
    std::string name;
    
    int chips = 0;
    bool fold = false;

    Player(){};
    Player(std::string name, std::vector<Card> cards): name(name), cards(cards) {};
    Player(std::string name): name(name) {};
    Player(std::string name, int chips): name(name), chips(chips) {};

    std::vector<Card> ShowCards(){ return this->cards; }
    void PushCards(std::vector<Card> cards);
};