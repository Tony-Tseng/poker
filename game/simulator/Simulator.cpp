#include "Simulator.hpp"

void Simulator::ShowWinTurns()
{
    for(auto turn: win_turns)
    {
        std::cout << turn << " ";
    }
    std::cout << std::endl;
    return;
}