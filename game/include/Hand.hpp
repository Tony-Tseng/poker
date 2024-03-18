#pragma once
#include<vector>
#include<iostream>

#include "Card.hpp"

static std::vector<std::string> hand_name = 
{
    "Invalid", "High card", "One Pair", "Two Pairs", "Three of a kind", 
    "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush"
};

class Hand
{
public:
    int category;
    std::vector<Card> cards;

    Hand(int category, std::vector<Card> cards): category(category), cards(cards) {}
    Hand(): category(0){};

    bool operator==(Hand& hand);
    bool operator>(Hand& hand);
    bool operator<(Hand& hand);
};

class StraightFlushHand : public Hand
{
public:
    StraightFlushHand(std::vector<Card> cards): Hand(9, cards){};
    StraightFlushHand(): Hand(){};
};

class FourOfAKindHand : public Hand
{
public:
    FourOfAKindHand(std::vector<Card> cards): Hand(8, cards){};
    FourOfAKindHand(): Hand(){};
};

class FullHouseHand : public Hand
{
public:
    FullHouseHand(std::vector<Card> cards): Hand(7, cards){};
    FullHouseHand(): Hand(){};
};

class FlushHand : public Hand
{
public:
    FlushHand(std::vector<Card> cards): Hand(6, cards){};
    FlushHand(): Hand(){};
};

class StraightHand : public Hand
{
public:
    StraightHand(std::vector<Card> cards): Hand(5, cards){};
    StraightHand(): Hand(){};
};

class ThreeOfAKindHand : public Hand
{
public:
    ThreeOfAKindHand(std::vector<Card> cards): Hand(4, cards){};
    ThreeOfAKindHand(): Hand(){};
};

class TwoPairsHand : public Hand
{
public:
    TwoPairsHand(std::vector<Card> cards): Hand(3, cards){};
    TwoPairsHand(): Hand(){};
};

class OnePairHand : public Hand
{
public:
    OnePairHand(std::vector<Card> cards): Hand(2, cards){};
    OnePairHand(): Hand(){};
};

class HighcardHand : public Hand
{
public:
    HighcardHand(std::vector<Card> cards): Hand(1, cards){};
    HighcardHand(): Hand(){};
};