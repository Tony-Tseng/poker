#include "Utils.hpp"

int combination(int N, int R){
    float comb = 1;
    if( R > N ) return (int) 0;

    for(int i = 1;i<=(N-R);i++)
    {
        comb = comb * (N+1-i)/i;
    }

    return std::round(comb);
}

std::vector<Card> GetCombinationCardsByIndexing(Deck deck, int index, int len)
{
    std::vector<Card> cards;
    int M = (int) deck.ShowCards().size() - 1;
    int R = len;
    int calc = combination(M, R);

    while( cards.size() < len )
    {
        if( calc > index )
        {
            calc = combination(--M, R);
        }
        else
        {
            cards.push_back(deck.GetCard(deck.ShowCards().size()-M-1));
            index -= calc;
            calc = combination(--M, --R);
        }
    }
    return cards;
}