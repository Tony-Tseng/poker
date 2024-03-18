#pragma once
#include <mutex> 

#include "Simulator.hpp"
#include "Utils.hpp"
#include "ThreadPool.hpp"
#include "Display.hpp"

class ThreadSimulator : public Simulator
{
private:
    std::mutex mtx;
    size_t thread_num = std::thread::hardware_concurrency();
public:
    ThreadSimulator();
    ThreadSimulator(Deck deck, Board board, std::vector<Player> players) : Simulator(deck, board, players){};
    ~ThreadSimulator() {};

    void Simulate();
};