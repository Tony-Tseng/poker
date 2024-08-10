#include "AllRangeSimulator.hpp"

void AllRangeSimulator::Simulate()
{
    ThreadPool pool(thread_num);
    int sim_num = combination(deck.ShowCards().size(), 2);
    std::cout << "Listing all " << sim_num << " kinds of hands the oppenents have." << std::endl;
    
    for(int i=0;i<sim_num;i++)
    {
        pool.enqueue(
            [i, this] {
                std::vector<Card> cards = GetCombinationCardsByIndexing(deck, i, 2);
                Deck tmp_deck = deck;
                std::string card_type = GetCardType(cards);
                int index = GetTableIndex(card_type);

                for(auto card: cards)
                {
                    tmp_deck.Remove(card);
                }
                Player opponent = Player("fake", cards);

                Simulator* simulator = CreateSimulator("thread", tmp_deck, board, {player, opponent});
                simulator->Simulate();
                std::vector<int> win_turns = simulator->GetWinTurns();

                // Need to lock for race conditions
                auto lock = std::unique_lock<std::mutex>(mtx);
                all_range_win_turns[index][0] += win_turns[0];
                all_range_win_turns[index][1] += win_turns[1];
                all_range_win_turns[index][2] += win_turns[2];
                simulation_cnt[index] = simulation_cnt[index] + win_turns[0] + win_turns[1] + win_turns[2];
            }
        );
    }
}

void AllRangeSimulator::ShowDeck()
{
    display(deck);
    return;
}

void AllRangeSimulator::ShowAllRangeWinTurns()
{
    float win_cnt[all_range_win_turns[0].size()];
    memset(win_cnt, 0, sizeof(win_cnt));
    for( int i = 0; i < all_range_win_turns.size(); i++ )
    {
        std::cout << GetCardTypeByIndex(i) << " : ";
        for(int j=0;j<3;j++)
            std::cout << RoundByDecimalsPlaces(all_range_win_turns[i][j], simulation_cnt[i], 2) << " ";
        std::cout << std::endl;

        auto max_idx = std::max_element(all_range_win_turns[i].begin(), all_range_win_turns[i].end());
        win_cnt[std::distance(all_range_win_turns[i].begin(), max_idx)]++;
    }

    for(int i=0;i<all_range_win_turns[0].size();i++)
    {
        std::cout << RoundByDecimalsPlaces(win_cnt[i], 169.0, 2) << " ";
    }
    std::cout << std::endl;
}

int AllRangeSimulator::ShowAllRangeTable(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    for( int i = 0; i < all_range_win_turns.size(); i++ )
    {
        std::vector<float> ratio(3, 0.0);
        for(int j=0;j<3;j++)
        {
            ratio[j] = RoundByDecimalsPlaces(all_range_win_turns[i][j], simulation_cnt[i], 2);
        }
        w.AddItem(i, (const char*)GetCardTypeByIndex(i).c_str(), ratio);
    }

    w.show();
    return a.exec();
}