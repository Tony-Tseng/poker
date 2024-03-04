#include "poker.hpp"

void Poker::DoReady()
{
    // All player are ready to play.
    // Check there is no chips on the table.
    // The deck should be shuffled before starting.
    for(int i=0;i<this->players.size();i++)
    {
        this->players[i].fold = false;
        if( this->chips[i] != 0 )
        {
            std::cerr << "The chips are left on the table" << std::endl;
            stage = End;
        }
    }

    if( deck.ShowCards().size() != deck.CorrectCardNum() )
    {
        std::cerr << "The number of cards should not be " << deck.ShowCards().size() << "." << std::endl;
        stage = End;
    }
    else{
        deck.Shuffle();
        stage = PreFlop;
    }
}

void Poker::DoPreFlop()
{
    for(int i=0;i<this->players.size();i++)
    {
        if( !this->players[i].fold )
        {
            this->players[i].PushCards( deck.Deal(2) );
        }
    }
    // Bet Stage
    // To-do

    stage = Flop;
}

void Poker::DoFlop()
{
    board.PushCards( deck.Deal(3) );
    // Bet Stage
    // To-do

    stage = Turn;
}

void Poker::DoTurn()
{
    board.PushCards( deck.Deal(1) );
    // Bet Stage
    // To-do

    stage = River;
}

void Poker::DoRiver()
{
    board.PushCards( deck.Deal(1) );
    // Bet Stage
    // To-do

    stage = Settle;
}

void Poker::DoSettle()
{
    std::vector<std::pair<std::shared_ptr<Hand>, int>> player_hands = GetPlayerHands(this->board);
    std::vector<std::pair<std::shared_ptr<Hand>, int>> winner = GetWinner(player_hands);
    // To-do
    // Settle the chips and recycle the cards.
    
    DisplayWinner(winner);

    stage = Ready;
}

void Poker::DoEnd()
{
    DisplayResult();
}

std::vector<std::pair<std::shared_ptr<Hand>, int>> Poker::GetPlayerHands(Board board)
{
    std::vector<std::pair<std::shared_ptr<Hand>, int>> player_hands;
    for( int i=0;i<this->players.size();i++)
    {
        if(!this->players[i].fold)
        {
            HandType hand_type(this->players[i], board);
            std::shared_ptr<Hand> hand = hand_type.PickTopHand();
            player_hands.push_back({hand, i});
        }
    }
    return player_hands;
}


std::vector<std::pair<std::shared_ptr<Hand>, int>> Poker::GetWinner(std::vector<std::pair<std::shared_ptr<Hand>, int>>& player_hands)
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

void Poker::CalculateCombination(std::vector<int>& win_turns, int idx, int deal_num)
{   
    if(deal_num==0)
    {
        std::vector<std::pair<std::shared_ptr<Hand>, int>> player_hands = GetPlayerHands(this->board);
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
            this->board.PushCards({deck.GetCard(i)});
            CalculateCombination(win_turns, i+1, deal_num-1);
            this->board.PopCards(1);
        }
    }
    return;
}

bool hand_compare(std::pair<std::shared_ptr<Hand>, int> a, std::pair<std::shared_ptr<Hand>, int> b)
{
    if( *a.first == *b.first ) return a.second < b.second;
    else return *a.first > *b.first;
}

void Poker::NextStage()
{
    switch ( stage )
    {
        case Ready:
            DoReady();
            break;
        case PreFlop:
            DoPreFlop();
            break;
        case Flop:
            DoFlop();
            break;
        case Turn:
            DoTurn();
            break;
        case River:
            DoRiver();
            break;
        case Settle:
            DoSettle();
            break;
        case End:
            DoEnd();
            break;
        default:
            std::cerr << "Unknown stage " << stage << std::endl;
            break;
    }
}

void Poker::Simulate()
{
    std::vector<int> win_turns(players.size()+1, 0);
    CalculateCombination(win_turns, 0, 5-board.ShowCards().size());

    for(auto turn: win_turns)
    {
        std::cout << turn << " ";
    }
    std::cout << std::endl;
}

void Poker::DisplayPlayerCards()
{
    for( auto& player : players)
    {
        if( player.fold )
        {
            std::cout << "Player " << player.name << " has fold. " << std::endl;
        }
        else
        {
            display(player);
        }
    }
}

void Poker::DisplayBoardCards()
{
    display(board);
}

void Poker::DisplayDeckCards()
{
    display(deck);
}

void Poker::DisplayStage() 
{ 
    std::cout << "Current Stage is - " << stage_text[this->stage] << std::endl;
    return;
}

void Poker::DisplayResult()
{
    Player best_player = players[0];
    int best_chips = players[0].chips;
    for(auto& player: players)
    {
        std::cout << "Player " << player.name << " has " << player.chips << " chips." << std::endl;
        if( player.chips > best_chips )
        {
            best_chips = player.chips;
            best_player = player;
        }
    }
    std::cout << "Player " << best_player.name << " win the game with " \
                << best_chips << " chips." << std::endl;
    return;
}

void Poker::DisplayWinner(std::vector<std::pair<std::shared_ptr<Hand>, int>> winner) 
{
    std::cout << "The winner of this round ";
    if( winner.size() == 1 )
    {
        std::cout << "is " << this->players[winner[0].second].name << std::endl;
        display(winner[0].first);
    }
    else
    {
        std::cout << "are " << std::endl;
        for( auto w: winner )
        {
            std::cout << this->players[w.second].name << " " << std::endl;
            display(w.first);
        }
    }
    return;
} 