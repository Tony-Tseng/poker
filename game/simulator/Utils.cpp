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

std::string GetCardType(std::vector<Card> cards)
{
    std::string card_type = "";
    if( cards.size() != 2 )
    {
        std::cerr << "More than two cards" << std::endl;
        return "Invalid card numbers";
    }

    if( cards[0].number < cards[1].number )
    {
        Card tmp = cards[0];
        cards[0] = cards[1];
        cards[1] = tmp;
    }

    if( cards[1].number == cards[0].number )
    {
        card_type = number_text[cards[0].number] + number_text[cards[1].number] + "p";
    }
    else if( cards[0].suit == cards[1].suit)
    {
        card_type = number_text[cards[0].number] + number_text[cards[1].number] + "s";
    }
    else
    {
        card_type = number_text[cards[0].number] + number_text[cards[1].number] + "o";
    }
    return card_type;
}

int GetTableIndex(std::string card_type)
{
    int index = 0;
    int r = 12 - number_text_to_int[card_type[0]];
    int c = 12 - number_text_to_int[card_type[1]];

    if( card_type[2] == 's')
    {
        index = r * 13 + c;
    }
    else
    {
        index = c * 13 + r;
    }
    return index;
}

std::string GetCardTypeByIndex(int index)
{
    int c = index % 13;
    int r = index / 13;
    std::string card_type = "";

    if( r == c )
    {
        card_type = number_text[12-r] + number_text[12-c] + 'p';
    } 
    else if( r > c )
    {
        card_type = number_text[12-c] + number_text[12-r] + 'o';
    } 
    else
    {
        card_type = number_text[12-r] + number_text[12-c] + 's';
    } 

    return card_type;
}

float RoundByDecimalsPlaces(int num, int denom, int place)
{
    int mult = std::pow(10, place);
    return std::ceil(num*mult / denom)/mult;
}