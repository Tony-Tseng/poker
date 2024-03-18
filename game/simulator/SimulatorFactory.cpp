#include "SimulatorFactory.hpp"

Simulator* CreateSimulator(std::string methods, Deck deck, Board board, std::vector<Player> players)
{
    if( methods == "naive")
        return static_cast<Simulator*>(new NaiveSimulator(deck, board, players));
    else if( methods == "thread")
        return static_cast<Simulator*>(new ThreadSimulator(deck, board, players));
    else
    {
        std::cerr << "Method not supported" << std::endl;
        return nullptr;
    }
}