#include "CompareHands.hpp"

std::vector<std::pair<std::shared_ptr<Hand>, int>> GetPlayerHands(Board board, std::vector<Player> players)
{
    std::vector<std::pair<std::shared_ptr<Hand>, int>> player_hands;
    for( int i=0;i<players.size();i++)
    {
        if(!players[i].fold)
        {
            HandType hand_type(players[i], board);
            std::shared_ptr<Hand> hand = hand_type.PickTopHand();
            player_hands.push_back({hand, i});
        }
    }
    return player_hands;
}


std::vector<std::pair<std::shared_ptr<Hand>, int>> GetWinner(std::vector<std::pair<std::shared_ptr<Hand>, int>>& player_hands)
{
    std::vector<std::pair<std::shared_ptr<Hand>, int>> winner;
    std::sort(player_hands.begin(), player_hands.end(), hand_compare);
    winner.push_back(player_hands[0]);

    int i = 1;
    while(i < player_hands.size() && *player_hands[0].first == *player_hands[i].first)
    {
        winner.push_back( player_hands[i] );
        i++;
    }

    return winner;
}

bool hand_compare(std::pair<std::shared_ptr<Hand>, int> a, std::pair<std::shared_ptr<Hand>, int> b)
{
    if( *a.first == *b.first ) return a.second < b.second;
    else return *a.first > *b.first;
}