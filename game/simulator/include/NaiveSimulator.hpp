#pragma once
#include "Simulator.hpp"

class NaiveSimulator : public Simulator
{
private:
    void CalculateCombination(int idx, int deal_num);
public:
    NaiveSimulator(){};
    NaiveSimulator(Deck deck, Board board, std::vector<Player> players) : Simulator(deck, board, players){};
    void Simulate();
};