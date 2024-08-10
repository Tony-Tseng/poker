#pragma once
#include "Board.hpp"
#include "CompareHands.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "HandType.hpp"

class Simulator
{
protected:
    Deck deck;
    Board board;
    std::vector<Player> players;
    std::vector<int> win_turns;
public:
    Simulator();
    virtual ~Simulator() = default;
    Simulator(Deck deck, Board board, std::vector<Player> players): deck(deck), board(board), players(players)
    {
        win_turns = std::vector<int>(players.size()+1, 0);
    }
    virtual void Simulate() = 0;
    void ShowWinTurns();
    std::vector<int> GetWinTurns() {return this->win_turns;}
};