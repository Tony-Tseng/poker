#include "AllRangeSimulatorFactory.hpp"

AllRangeSimulator* CreateAllRangeSimulator(std::string methods, Board board, Player player)
{
    return new AllRangeSimulator(board, player);
}