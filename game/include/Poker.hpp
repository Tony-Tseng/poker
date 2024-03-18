#pragma once
#include<vector>

#include "Board.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"
#include "Display.hpp"
#include "HandType.hpp"
#include "CompareHands.hpp"
#include "Simulator.hpp"
#include "SimulatorFactory.hpp"

enum Stage {Ready, PreFlop, Flop, Turn, River, Settle, End};
static std::string stage_text[7] = {"Ready", "PreFlop", "Flop", "Turn", "River", "Settle", "End"};

class Poker
{
private:
    std::vector<Player> players;
    std::vector<int> chips;
    Deck deck;
    Board board;
    Stage stage = Ready;

    void DoReady();
    void DoPreFlop();
    void DoFlop();
    void DoTurn();
    void DoRiver();
    void DoSettle();
    void DoEnd();

public:
    Poker()
    {
        std::cerr << "Please add players in the poker game" << std::endl;
    }

    Poker(std::vector<Player> players, Deck deck): players(players), deck(deck) 
    {
        chips = std::vector<int>(players.size(), 0);
    }
    Poker(std::vector<Player> players): players(players) 
    {
        chips = std::vector<int>(players.size(), 0);
        deck.Initialize();
        deck.Shuffle();
    }

    void NextStage();
    void Simulate(std::string methods);

    void DisplayPlayerCards();
    void DisplayPlayerCards(int seat);
    void DisplayBoardCards();
    void DisplayDeckCards();
    void DisplayStage();
    void DisplayResult();
    void DisplayWinner(std::vector<std::pair<std::shared_ptr<Hand>, int>> winner);
};