#include "NaiveSimulator.hpp"

void NaiveSimulator::CalculateCombination(int idx, int deal_num)
{   
    if(deal_num==0)
    {
        std::vector<std::pair<std::shared_ptr<Hand>, int>> player_hands = GetPlayerHands(board, players);
        std::vector<std::pair<std::shared_ptr<Hand>, int>> winner = GetWinner(player_hands);
        
        if( winner.size() == 1 )
        {
            win_turns[winner[0].second]++;
        }
        else
        {
            win_turns[win_turns.size()-1]++;
        }
    }
    else
    {
        for(int i = idx; i <= deck.ShowCards().size()-deal_num; i++)
        {
            board.PushCards({deck.GetCard(i)});
            CalculateCombination(i+1, deal_num-1);
            board.PopCards(1);
        }
    }
    return;
}

void NaiveSimulator::Simulate()
{
    CalculateCombination(0, 5-board.ShowCards().size());
    return;
}