#include "hand.hpp"

bool Hand::operator==(Hand& hand)
{
    if(this->category == 0 || hand.category == 0)
    {
        // std::cerr << "Invalid hands" << std::endl;
        return false;
    }
    if(this->category == hand.category)
    {
        bool is_equal = true;
        for(int i=0; i<5 && is_equal;i++)
        {
            if( this->cards[i] != hand.cards[i] ) is_equal = false;
        }
        return is_equal;
    }
    else return false;
}

bool Hand::operator>(Hand& hand)
{
    if(this->category == 0 || hand.category == 0)
    {
        // std::cerr << "Invalid hands" << std::endl;
        return false;
    }
    if( this->category == hand.category )
    {
        for(int i=0; i<5;i++)
        {
            if( this->cards[i] > hand.cards[i] ) return true;
            else if(this->cards[i] < hand.cards[i] ) return false;
        }
        return false;
    }
    else return this->category > hand.category;
}

bool Hand::operator<(Hand& hand)
{
    if(this->category == 0 || hand.category == 0)
    {
        // std::cerr << "Invalid hands" << std::endl;
        return false;
    }
    if( this->category == hand.category )
    {
        for(int i=0; i<5;i++)
        {
            if( this->cards[i] < hand.cards[i] ) return true;
            else if( this->cards[i] > hand.cards[i] ) return false;
        }
        return false;
    }
    else return this->category < hand.category;
}