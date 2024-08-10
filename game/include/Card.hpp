#pragma once
#include <string>
#include <iostream>

enum Suits {Spade=0, Heart, Diamond, Club};
static std::string suits_text[4] = {"S", "H", "D", "C"};
static std::string number_text[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
static std::unordered_map<char, int> number_text_to_int = 
{
    std::make_pair('A', 12),
    std::make_pair('K', 11),
    std::make_pair('Q', 10),
    std::make_pair('J', 9),
    std::make_pair('T', 8),
    std::make_pair('9', 7),
    std::make_pair('8', 6),
    std::make_pair('7', 5),
    std::make_pair('6', 4),
    std::make_pair('5', 3),
    std::make_pair('4', 2),
    std::make_pair('3', 1),
    std::make_pair('2', 0)
};

static std::unordered_map<char, int> suit_text_to_int = 
{
    std::make_pair('S', 0),
    std::make_pair('H', 1),
    std::make_pair('D', 2),
    std::make_pair('C', 3)
};

class Card{
public:
    Suits suit;
    int number;

    Card(){};
    Card(Suits suit, int number): suit(suit), number(number){};
    Card(std::string card_str)
    {
        if( card_str.size() != 2 )
        {
            std::cerr << "Invalid card string" << std::endl;
            throw;
        }
        suit = Suits(suit_text_to_int[card_str[0]]);
        number = number_text_to_int[card_str[1]];
    }
    bool operator==(Card const& c) const;
    bool operator!=(Card const& c) const;
    bool operator>(Card const& c) const;
    bool operator<(Card const& c) const;
};