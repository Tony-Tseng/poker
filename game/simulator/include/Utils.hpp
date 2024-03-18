#pragma once
#include "Card.hpp"
#include "Deck.hpp"

int combination(int N, int R);
std::vector<Card> GetCombinationCardsByIndexing(Deck deck, int index, int len);