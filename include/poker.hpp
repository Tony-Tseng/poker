#pragma once
#include<vector>

#include "board.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "display.hpp"
#include "handtype.hpp"

enum Stage {Ready, PreFlop, Flop, Turn, River, Settle, End};
static std::string stage_text[7] = {"Ready", "PreFlop", "Flop", "Turn", "River", "Settle", "End"};
bool hand_compare(std::pair<std::shared_ptr<Hand>, int> a, std::pair<std::shared_ptr<Hand>, int> b);

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
    
    std::vector<std::pair<std::shared_ptr<Hand>, int>> GetWinner(std::vector<std::pair<std::shared_ptr<Hand>, int>>& player_hands);
    std::vector<std::pair<std::shared_ptr<Hand>, int>> GetPlayerHands(Board board);
    void CalculateCombination(std::vector<int>& win_turns, int idx, int deal_num);
    
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
    void Simulate();

    void DisplayPlayerCards();
    void DisplayPlayerCards(int seat);
    void DisplayBoardCards();
    void DisplayDeckCards();
    void DisplayStage();
    void DisplayResult();
    void DisplayWinner(std::vector<std::pair<std::shared_ptr<Hand>, int>> winner);
};