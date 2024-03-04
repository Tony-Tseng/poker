#include<iostream>
#include"card.hpp"
#include"player.hpp"
#include"hand.hpp"
#include"display.hpp"
#include"handtype.hpp"
#include"poker.hpp"

int main(){
    // Card card1(Suits(3), 11);
    // Card card2(Suits(1), 10);
    // Card card3(Suits(2), 2);
    // Card card4(Suits(3), 2);
    // Card card5(Suits(0), 11);

    // Card card6(Suits(0), 4);
    // Card card7(Suits(0), 8);

    // Card card8(Suits(2), 1);
    // Card card9(Suits(3), 0);

    // Board b({card1, card2, card3, card4, card5});

    // Player p1("Tony", {card6, card7}), p2("Alan", {card8, card9});

    // HandType hand_type1(p1, b);
    // Hand* p1_hand = hand_type1.PickTopHand();

    // HandType hand_type2(p2, b);
    // Hand* p2_hand = hand_type2.PickTopHand();

    // bool flag = ( (*p1_hand) > (*p2_hand) );
    // std::cout << "Player " << (flag? "1": "2")  <<" is winner!" << std::endl;

    // display(p1_hand);
    // display(p2_hand);

    Player p1("Tony"), p2("Alan");
    Poker poker({p1, p2});
    // Ready
    // poker.DisplayStage();
    poker.NextStage();

    // PreFlop
    // poker.DisplayStage();
    poker.NextStage();
    poker.DisplayPlayerCards();

    // Flop
    poker.DisplayStage();
    poker.NextStage();

    // Turn
    poker.DisplayStage();
    poker.DisplayBoardCards();
    poker.DisplayDeckCards();
    poker.Simulate();

    // poker.NextStage();

    // River
    // poker.DisplayStage();
    // poker.NextStage();

    // Settle
    // poker.DisplayStage();
    // poker.NextStage();

    // poker.NextStage();
}