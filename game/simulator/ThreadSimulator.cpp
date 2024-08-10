#include "ThreadSimulator.hpp"

void ThreadSimulator::Simulate()
{
    ThreadPool pool(thread_num);
    int sim_num = combination(deck.ShowCards().size(), 5-board.ShowCards().size());
    // std::cout << "Listing all " << sim_num << " kinds of possibilities." << std::endl;
    
    for(int i=0;i<sim_num;i++)
    {
        pool.enqueue(
            [i, this] {
                std::vector<Card> cards = GetCombinationCardsByIndexing(deck, i, 5-board.ShowCards().size());
                Board sim_board = board;
                sim_board.PushCards(cards);

                std::vector<std::pair<std::shared_ptr<Hand>, int>> player_hands = GetPlayerHands(sim_board, players);
                std::vector<std::pair<std::shared_ptr<Hand>, int>> winner = GetWinner(player_hands);
                
                // Need to lock for race conditions
                auto lock = std::unique_lock<std::mutex>(mtx);
                if( winner.size() == 1 ) win_turns[winner[0].second]++;
                else win_turns[win_turns.size()-1]++;
            }
        );
    }
    return;
}