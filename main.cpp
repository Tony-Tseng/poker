#include <iostream>
#include "Card.hpp"
#include "Player.hpp"
#include "Hand.hpp"
#include "Display.hpp"
#include "HandType.hpp"
#include "Poker.hpp"

#include "app/mainwindow.hpp"
// Spade, Heart, Diamond, Club

int main(int argc, char *argv[]){
    Player p1("Tony", {Card("DT"), Card("H9")});
    Player p2("Alan", {Card("SQ"), Card("D9")});
    // Player p2("Alan");
    // Player p3("Bob");
    Board board({Card("D7"), Card("HT"), Card("DJ"), Card("HJ")});
    // Board board({Card("CQ"), Card("S8"), Card("C7"), Card("C6")});
    // Board board({Card("CQ"), Card("S8"), Card("C7"), Card("C6"), Card("C6")});
    // Board board;
    Poker poker({p1, p2}, board);
    // Ready
    poker.DisplayStage();
    poker.NextStage();

    // PreFlop
    // poker.DisplayStage();
    // poker.NextStage();
    poker.DisplayPlayerCards();

    // Flop
    // poker.DisplayStage();
    // poker.NextStage();

    poker.DisplayBoardCards();
    poker.DisplayDeckCards();
    auto simulator = poker.SimulateAllRange("Thread", "Tony");
    // simulator->ShowAllRangeWinTurns();
    simulator->ShowAllRangeTable(argc, argv);
    // poker.SimulateBattle("thread");
    // // poker.SimulateBattle("naive");

    // // Turn
    // // poker.DisplayStage();
    // // poker.NextStage();

    // // River
    // // poker.DisplayStage();
    // // poker.NextStage();

    // // Settle
    // // poker.DisplayStage();
    // // poker.NextStage();

    // // poker.NextStage();

    // test_window(argc, argv);
}