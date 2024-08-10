#pragma once
#include "Card.hpp"
#include "Deck.hpp"

int combination(int N, int R);
std::vector<Card> GetCombinationCardsByIndexing(Deck deck, int index, int len);
std::string GetCardTypeByIndex(int index);
int GetTableIndex(std::string card_type);
std::string GetCardType(std::vector<Card> cards);
float RoundByDecimalsPlaces(int num, int denom, int place);