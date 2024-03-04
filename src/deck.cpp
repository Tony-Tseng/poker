#include<deck.hpp>

void Deck::Initialize()
{
    std::vector<Card> new_cards;
    for(int i=0;i<S;i++){
        for(int j=0;j<N;j++){
            Card card(Suits(i), j);
            new_cards.push_back(card);
        }
    }
    cards = new_cards;
}

bool Deck::Remove(Card card)
{
    for (std::vector<Card>::iterator it=cards.begin(); it!=cards.end();)
    {
        Card &deck_card = *it;
        if( deck_card.suit == card.suit && deck_card.number == card.number )
        {
            it = cards.erase(it);
            return true;
        }
        else ++it;
    }
    std::cerr << "card do not exist" << std::endl;
    return false;
}

bool Deck::Add(Card card)
{
    for (std::vector<Card>::iterator it=cards.begin(); it!=cards.end();)
    {
        Card &deck_card = *it;
        if( deck_card.suit == card.suit && deck_card.number == card.number )
        {
            std::cerr << "card already in the deck" << std::endl;
            return false;
        }
        else ++it;
    }
    cards.push_back(card);
    return true;
}

std::vector<Card> Deck::Deal(int nums=1)
{
    std::vector<Card> deal_cards;
    for( int i = 0; i < nums; i++ )
    {
        deal_cards.push_back(cards.back());
        cards.pop_back();
    }

    return deal_cards;
}

void Deck::Shuffle()
{
    /*
        Random shuffle function
    */
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned seed = 10283;
    std::default_random_engine e(seed);
    std::shuffle(std::begin(cards), std::end(cards), e);
}

bool card_compare(Card a, Card b)
{
    if( a.suit == b.suit ) return a.number < b.number;
    else return a.suit < b.suit;
}

void Deck::Sort()
{
    std::sort(cards.begin(), cards.end(), card_compare);
}