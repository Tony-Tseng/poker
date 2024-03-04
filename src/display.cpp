#include "display.hpp"

void display(Card& card)
{
    std::cout << suits_text[card.suit] << number_text[card.number];
}

void display(Deck& deck)
{
    std::cout << "The Deck cards are: ";
    for(auto& c: deck.ShowCards()){
        display(c);
        std::cout << " ";
    }
    std::cout << std::endl;
}

void display(Board& board)
{
    std::cout << "The Board cards are: ";
    for(auto& c: board.ShowCards()){
        display(c);
        std::cout << " ";
    }
    std::cout << std::endl;
}

void display(Player& player)
{
    std::cout << "The player " << player.name << "'s cards are: ";
    for(auto& c: player.ShowCards()){
        display(c);
        std::cout << " ";
    }
    std::cout << std::endl;
}

void display(std::shared_ptr<Hand> hand)
{
    std::cout << "The hand is: " << hand_name[hand->category] << std::endl;
    std::cout << "The cards are: ";
    for(auto& c: hand->cards){
        display(c);
        std::cout << " ";
    }
    std::cout << std::endl;
}