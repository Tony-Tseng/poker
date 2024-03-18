#pragma once
#include "Simulator.hpp"
#include "NaiveSimulator.hpp"
#include "ThreadSimulator.hpp"

Simulator* CreateSimulator(std::string methods, Deck deck, Board board, std::vector<Player> players);