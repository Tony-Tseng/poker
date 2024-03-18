#include "HandType.hpp"

int CheckStraight(std::vector<int> number_table)
{
    int straight_start = -1;
    for (int n = 0; n < 9; n++)
    {
        if (number_table[n] == 1)
        {
            int straight_cnt = n;
            for (int s = 0; s < 5 && straight_cnt != -1; s++)
            {
                if (number_table[s + n] != 1)
                {
                    straight_cnt = -1;
                }
            }
            straight_start = std::max(straight_start, straight_cnt);
        }
    }
    return straight_start;
}

Card HandType::RemoveCard(Suits suit, int number)
{
    card_table[suit][number] = 0;
    suit_table[suit]--;
    number_table[number]--;
    Card c(suit, number);
    return c;
}

void HandType::AddCard(std::vector<Card> cards)
{
    for(auto c: cards)
    {
        card_table[c.suit][c.number] = 1;
        suit_table[c.suit]++;
        number_table[c.number]++;
    }
}

std::vector<Card> HandType::PickHighKinds(int number_of_kinds)
{
    std::vector<Card> cards;
    for (int n = 12; n > -1; n--)
    {
        if (number_table[n] > number_of_kinds - 1)
        {
            for (int s = 0; s < 4; s++)
            {
                if (card_table[s][n] == 1 && cards.size() < number_of_kinds)
                {
                    Card c = RemoveCard(Suits(s), n);
                    cards.push_back(c);
                }
            }
            return cards;
        }
    }
    return cards;
}

std::vector<Card> HandType::PickTopCards(Suits suit, int number_of_cards)
{
    std::vector<Card> cards;
    if (suit_table[suit] < number_of_cards) return cards;

    for (int n = 12; cards.size() < number_of_cards ; n--)
    {
        if( card_table[suit][n] == 1)   
        {
            Card c = RemoveCard(Suits(suit), n);
            cards.push_back(c);
        }
    }
    return cards;
}

std::vector<Card> HandType::PickTopCards(int number_of_cards)
{
    std::vector<Card> cards;
    for (int n = 12; cards.size() < number_of_cards ; n--)
    {
        for(int s=0; s<4 && cards.size() < number_of_cards; s++)
        {
            if( card_table[s][n] == 1)
            {
                Card c = RemoveCard(Suits(s), n);
                cards.push_back(c);
            }
        }
    }
    return cards;
}

std::shared_ptr<Hand> HandType::PickTopHand()
{
    std::shared_ptr<Hand> hand(new Hand());

    hand = PickStraightFlush();
    if( hand->category != 0 ) return hand;
    
    hand = PickFourOfAKind();
    if( hand->category != 0 ) return hand;

    hand = PickFullHouse();
    if( hand->category != 0 ) return hand;

    hand = PickFlush();
    if( hand->category != 0 ) return hand;

    hand = PickStraight();
    if( hand->category != 0 ) return hand;

    hand = PickThreeOfAKind();
    if( hand->category != 0 ) return hand;

    hand = PickTwoPairs();
    if( hand->category != 0 ) return hand;

    hand = PickOnePair();
    if( hand->category != 0 ) return hand;

    hand = PickHighCard();
    return hand;
}

std::shared_ptr<StraightFlushHand> HandType::PickStraightFlush()
{
    std::shared_ptr<StraightFlushHand> hand(static_cast<StraightFlushHand*>(new Hand()));
    for (int s = 0; s < 4; s++)
    {
        int straight_start = CheckStraight(card_table[s]);
        if (straight_start != -1)
        {
            std::vector<Card> straight_card;
            for (int i = 0; i < 5; i++)
            {
                Card c = RemoveCard(Suits(s), straight_start + i);
                straight_card.push_back(c);
            }
            std::shared_ptr<StraightFlushHand> straight_flush_hand(new StraightFlushHand(straight_card));
            hand = straight_flush_hand;
        }
    }
    return hand;
}

std::shared_ptr<FourOfAKindHand> HandType::PickFourOfAKind()
{
    std::shared_ptr<FourOfAKindHand> hand(static_cast<FourOfAKindHand*>(new Hand()));
    std::vector<Card> four_kind_card = PickHighKinds(4);
    if( four_kind_card.size() == 4)
    {
        std::vector<Card> high_card = PickTopCards(1);
        if( high_card.size() == 1 )
        {
            std::vector<Card> four_of_a_kind_card = four_kind_card;
            four_of_a_kind_card.push_back(high_card[0]);

            std::shared_ptr<FourOfAKindHand> four_of_a_kind_hand(new FourOfAKindHand(four_of_a_kind_card));
            hand = four_of_a_kind_hand;
        }
        else
        {
            AddCard(four_kind_card);
        }
    }

    return hand;
}

std::shared_ptr<FullHouseHand> HandType::PickFullHouse()
{
    std::shared_ptr<FullHouseHand> hand(static_cast<FullHouseHand*>(new Hand()));
    std::vector<Card> three_kind_card = PickHighKinds(3);
    if( three_kind_card.size() == 3 )
    {
        std::vector<Card> pair_card = PickHighKinds(2);
        if( pair_card.size() == 2 )
        {
            std::vector<Card> full_house_card = three_kind_card;
            full_house_card.push_back(pair_card[0]);
            full_house_card.push_back(pair_card[1]);

            std::shared_ptr<FullHouseHand> full_house_hand(new FullHouseHand(full_house_card));
            hand = full_house_hand;
        }
        else
        {
            AddCard(three_kind_card);
        }
    }

    return hand;
}

std::shared_ptr<FlushHand> HandType::PickFlush()
{
    std::shared_ptr<FlushHand> hand(static_cast<FlushHand*>(new Hand()));
    for(int s=0;s<4;s++)
    {
        if( suit_table[s] > 4 )
        {
            std::vector<Card> flush_cards = PickTopCards(Suits(s), 5);
            std::shared_ptr<FlushHand> flush_hand(new FlushHand(flush_cards));
            hand = flush_hand;
        }
    }
    return hand;
}

std::shared_ptr<StraightHand> HandType::PickStraight()
{
    std::shared_ptr<StraightHand> hand(static_cast<StraightHand*>(new Hand()));
    int straight_start = CheckStraight(number_table);
    if (straight_start != -1)
    {
        std::vector<Card> straight_card;
        for (int i = 0; i < 5; i++)
        {
            bool flag = false;
            for (int s = 0; s < 4 && !flag; s++)
            {
                if( card_table[s][straight_start+i] == 1 )
                {
                    Card c = RemoveCard(Suits(s), straight_start + i);
                    straight_card.push_back(c);
                    flag = true;
                }
            }
        }
        std::shared_ptr<StraightHand> straight_hand(new StraightHand(straight_card));
        hand = straight_hand;
    }
    return hand;
}

std::shared_ptr<ThreeOfAKindHand> HandType::PickThreeOfAKind()
{
    std::shared_ptr<ThreeOfAKindHand> hand(static_cast<ThreeOfAKindHand*>(new Hand()));
    std::vector<Card> three_kind_card = PickHighKinds(3);
    if( three_kind_card.size() == 3)
    {
        std::vector<Card> high_card = PickTopCards(2);
        if( high_card.size() == 2 )
        {
            three_kind_card.push_back(high_card[0]);
            three_kind_card.push_back(high_card[1]);

            std::shared_ptr<ThreeOfAKindHand> three_of_a_kind_hand(new ThreeOfAKindHand(three_kind_card));
            hand = three_of_a_kind_hand;
        }
        else
        {
            AddCard(three_kind_card);
        }
    }
    return hand;
}

std::shared_ptr<TwoPairsHand> HandType::PickTwoPairs()
{
    std::shared_ptr<TwoPairsHand> hand(static_cast<TwoPairsHand*>(new Hand()));
    std::vector<Card> high_pair1 = PickHighKinds(2);
    std::vector<Card> high_pair2 = PickHighKinds(2);
    if( high_pair1.size() == 2 && high_pair2.size() == 2 )
    {
        std::vector<Card> high_card1 = PickTopCards(1);
        std::vector<Card> two_pair_cards;
        two_pair_cards.push_back(high_pair1[0]);
        two_pair_cards.push_back(high_pair1[1]);
        two_pair_cards.push_back(high_pair2[0]);
        two_pair_cards.push_back(high_pair2[1]);
        two_pair_cards.push_back(high_card1[0]);

        std::shared_ptr<TwoPairsHand> two_pair_hand(new TwoPairsHand(two_pair_cards));
        hand = two_pair_hand;
    }
    else
    {
        AddCard(high_pair1);
        AddCard(high_pair2);
    }
    return hand;
}

std::shared_ptr<OnePairHand> HandType::PickOnePair()
{
    std::shared_ptr<OnePairHand> hand(static_cast<OnePairHand*>(new Hand()));
    std::vector<Card> high_pair = PickHighKinds(2);
    if( high_pair.size() == 2)
    {
        std::vector<Card> one_pair_cards;
        std::vector<Card> high_card = PickTopCards(3);
        if( high_card.size() == 3 )
        {
            one_pair_cards.push_back(high_pair[0]);
            one_pair_cards.push_back(high_pair[1]);
            one_pair_cards.push_back(high_card[0]);
            one_pair_cards.push_back(high_card[1]);
            one_pair_cards.push_back(high_card[2]);

            std::shared_ptr<OnePairHand> one_pair_hand(new OnePairHand(one_pair_cards));
            hand = one_pair_hand;
        }
        else
        {
            AddCard(high_pair);
        }
    }
    return hand;
}

std::shared_ptr<HighcardHand> HandType::PickHighCard()
{
    std::shared_ptr<HighcardHand> hand(static_cast<HighcardHand*>(new Hand()));
    std::vector<Card> high_card = PickTopCards(5);
    if( high_card.size() == 5)
    {
        std::shared_ptr<HighcardHand> high_card_hand(new HighcardHand(high_card));
        hand = high_card_hand;
    }
    return hand;
}