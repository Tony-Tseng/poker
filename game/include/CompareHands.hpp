#pragma once
#include "Hand.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "HandType.hpp"

bool hand_compare(std::pair<std::shared_ptr<Hand>, int> a, std::pair<std::shared_ptr<Hand>, int> b);
std::vector<std::pair<std::shared_ptr<Hand>, int>> GetPlayerHands(Board board, std::vector<Player> players);
std::vector<std::pair<std::shared_ptr<Hand>, int>> GetWinner(std::vector<std::pair<std::shared_ptr<Hand>, int>>& player_hands);