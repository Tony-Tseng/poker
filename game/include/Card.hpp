#pragma once
#include <string>

enum Suits {Spade=0, Heart, Diamond, Club};
static std::string suits_text[4] = {"S", "H", "D", "C"};
static std::string number_text[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};

class Card{
public:
    Suits suit;
    int number;

    Card(){};
    Card(Suits suit, int number): suit(suit), number(number){};
    bool operator==(Card const& c) const;
    bool operator!=(Card const& c) const;
    bool operator>(Card const& c) const;
    bool operator<(Card const& c) const;
};