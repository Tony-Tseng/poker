#pragma once

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Card.hpp"
#include "Board.hpp"
#include "Hand.hpp"
#include "Player.hpp"
#include "Display.hpp"

class HandType
{
private:
    std::vector<std::vector<int>> card_table = std::vector<std::vector<int>> (4, std::vector<int>(13, 0));
    std::vector<int> suit_table = std::vector<int> (4, 0);
    std::vector<int> number_table = std::vector<int> (13, 0);

    Card RemoveCard(Suits s, int number);
    void AddCard(std::vector<Card> cards);
    std::vector<Card> PickHighKinds(int number_of_kinds);
    std::vector<Card> PickTopCards(Suits suit, int number_of_cards);
    std::vector<Card> PickTopCards(int number_of_cards);
public:
    HandType(){};
    HandType(Player p, Board b)
    {
        for(auto c: p.ShowCards())
        {
            if(card_table[c.suit][c.number] == 1)
            {
                std::cerr << c.suit << " " << c.number << std::endl;
                display(p);
                display(b);
                std::cerr << "Duplicate cards " << suits_text[c.suit] << number_text[c.number] << std::endl;
            }
            card_table[c.suit][c.number] = 1;
            suit_table[c.suit]++;
            number_table[c.number]++;
        }
        for(auto c: b.ShowCards())
        {
            if(card_table[c.suit][c.number] == 1)
            {
                std::cerr << c.suit << " " << c.number << std::endl;
                display(p);
                display(b);
                std::cerr << "Duplicate cards " << suits_text[c.suit] << number_text[c.number] << std::endl;
            }
            card_table[c.suit][c.number] = 1;
            suit_table[c.suit]++;
            number_table[c.number]++;
        }
    }
    HandType(std::vector<Card> cards)
    {
        for(auto c: cards)
        {
            if(card_table[c.suit][c.number] == 1)
            {
                std::cerr << "Duplicate cards " << suits_text[c.suit] << number_text[c.number] << std::endl;
            }
            card_table[c.suit][c.number] = 1;
            suit_table[c.suit]++;
            number_table[c.number]++;
        }
    }

    std::shared_ptr<Hand> PickTopHand();

    std::shared_ptr<StraightFlushHand> PickStraightFlush();
    std::shared_ptr<FourOfAKindHand> PickFourOfAKind();
    std::shared_ptr<FullHouseHand> PickFullHouse();
    std::shared_ptr<FlushHand> PickFlush();
    std::shared_ptr<StraightHand> PickStraight();
    std::shared_ptr<ThreeOfAKindHand> PickThreeOfAKind();
    std::shared_ptr<TwoPairsHand> PickTwoPairs();
    std::shared_ptr<OnePairHand> PickOnePair();
    std::shared_ptr<HighcardHand> PickHighCard();
};