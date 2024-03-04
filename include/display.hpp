#pragma once
#include<iostream>
#include<memory>
#include "card.hpp"
#include "deck.hpp"
#include "board.hpp"
#include "hand.hpp"
#include "player.hpp"

void display(Card& card);
void display(Deck& deck);
void display(Board& board);
void display(Player& player);
void display(std::shared_ptr<Hand> hand);