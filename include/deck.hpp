#pragma once
#include <vector>
#include <algorithm>
#include <random>

#include<iostream>
#include "card.hpp"

class Deck{
private:
    int S = 4;
    int N = 13;
    std::vector<Card> cards;
public:
    Deck(){ Initialize();}
    Deck(std::vector<Card> cards): cards(cards) {};

    void Initialize();
    bool Remove(Card card);
    bool Add(Card card);
    Card GetCard(int index) {return cards[index];}
    std::vector<Card> Deal(int nums);
    void Shuffle();
    void Sort();
    int CorrectCardNum() { return S*N; }
    std::vector<Card> ShowCards() { return this->cards; }
};