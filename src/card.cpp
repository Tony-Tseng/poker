#include <card.hpp>

bool Card::operator==(Card const& c) const
{ 
    return number == c.number;
}

bool Card::operator!=(Card const& c) const
{ 
    return number != c.number;
}

bool Card::operator>(Card const& c) const
{ 
    return number > c.number;
}

bool Card::operator<(Card const& c) const
{ 
    return number < c.number;
}