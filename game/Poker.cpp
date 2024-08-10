#include "Poker.hpp"

void Poker::InitDeck()
{
    deck.Initialize();
    for(auto player: players)
    {
        if( player.ShowCards().size() > 0 )
        {
            for(auto card: player.ShowCards() )
            {
                deck.Remove(card);
            }
        }
    }

    for(auto card: board.ShowCards())
    {
        deck.Remove(card);
    }

    deck.Shuffle();
    return;
}


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

    int distribute_cards = 0;
    for( auto player: this->players)
    {
        distribute_cards += player.ShowCards().size();
    }
    distribute_cards += board.ShowCards().size();

    if( deck.ShowCards().size() != deck.CorrectCardNum()-distribute_cards )
    {
        std::cerr << "The number of cards should not be " << deck.ShowCards().size() << "." << std::endl;
        throw;
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
        if( !this->players[i].fold && this->players[i].ShowCards().size()==0 )
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
    if( board.ShowCards().size() == 0 )
    {
        board.PushCards(deck.Deal(3));
    }
    // Bet Stage
    // To-do

    stage = Turn;
}

void Poker::DoTurn()
{
    if( board.ShowCards().size() == 3 )
    {
        board.PushCards(deck.Deal(1));
    }
    // Bet Stage
    // To-do

    stage = River;
}

void Poker::DoRiver()
{
    if(board.ShowCards().size() == 4)
    {
        board.PushCards(deck.Deal(1));
    }
    // Bet Stage
    // To-do

    stage = Settle;
}

void Poker::DoSettle()
{
    std::vector<std::pair<std::shared_ptr<Hand>, int>> player_hands = GetPlayerHands(this->board, this->players);
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

void Poker::SimulateBattle(std::string methods)
{
    Simulator* simulator = CreateSimulator(methods, deck, board, players);
    simulator->Simulate();
    simulator->ShowWinTurns();
    return;
}

AllRangeSimulator* Poker::SimulateAllRange(std::string methods, std::string player_name)
{
    AllRangeSimulator* simulator = nullptr;
    for(auto player: players)
    {
        if( player.name == player_name )
        {
            simulator = CreateAllRangeSimulator(methods, board, player);
            simulator->Simulate();
        }
    }
    return simulator;
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