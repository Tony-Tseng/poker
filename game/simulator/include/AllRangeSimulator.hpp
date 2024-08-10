#pragma once

#include "Board.hpp"
#include "Deck.hpp"
#include "Display.hpp"
#include "Player.hpp"

#include "SimulatorFactory.hpp"
#include "Simulator.hpp"
#include "ThreadPool.hpp"
#include "Utils.hpp"

#include "mainwindow.hpp"

class AllRangeSimulator
{
protected:
    Board board;
    Player player;
    Deck deck;
    std::mutex mtx;
    size_t thread_num = std::thread::hardware_concurrency();
    std::vector<std::vector<int>> all_range_win_turns = std::vector<std::vector<int>> (169, std::vector<int>(3, 0));
    std::vector<int> simulation_cnt = std::vector<int> (169, 0);
public:
    AllRangeSimulator(){};
    AllRangeSimulator(Board board, Player player): board(board), player(player)
    {
        deck.Initialize();
        for(auto card: board.ShowCards())
        {
            deck.Remove(card);
        }
        for(auto card: player.ShowCards())
        {
            deck.Remove(card);
        }
    };

    void Simulate();
    void ShowDeck();
    void ShowAllRangeWinTurns();
    int ShowAllRangeTable(int argc, char *argv[]);
};