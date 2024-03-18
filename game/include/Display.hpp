#pragma once
#include<iostream>
#include<memory>
#include "Card.hpp"
#include "Deck.hpp"
#include "Board.hpp"
#include "Hand.hpp"
#include "Player.hpp"

void display(Card& card);
void display(Deck& deck);
void display(Board& board);
void display(Player& player);
void display(std::shared_ptr<Hand> hand);