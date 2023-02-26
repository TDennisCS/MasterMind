#include "game.h"

Game::Game()
{
    difficulty = 1;
    ResetGuess();
    ResetPattern();
    ResetStat();
    ResetTurn();

}

void Game::GetGameStatistics()
{
    cout << "'o' = correct guess, 'x' = wrong position and number,  '-' = correct number but wrong position" << endl;
    for (int index=0; index < difficulty; index++)
    {
        cout << stats[turn_counter].correct_positions[index]; 
    }
    
    cout << endl; 
}

bool Game::CheckGuess(Pattern current_guess)
{
    bool winning_guess= true;

    int value;
    int target;


    for (int index= 0; index < difficulty; index++)
    {
        value = current_guess.nums[index];
        target = correct_pattern.nums[index];
        if (target != value)
        {
            winning_guess = false;
        }
   
    }

    return winning_guess;
}

void Game::ResetGuess()
{
    for (int index = 0; index < 10; index++)
    {
        guesses[index].nums.clear();
    }
}

Pattern Game::GetGuess(int index)
{
    Pattern guess;

    guess = guesses[index];

    return guess;
}

void Game::AddGuess(Pattern current_guess)
{
    guesses[turn_counter-1] = current_guess;
}

void Game::ResetPattern()
{
    correct_pattern.nums.clear();

    srand(time(NULL));

    int value;

    for (int index = 0; index < difficulty; index++)
    {
        value = rand()%difficulty + 1;
        
        correct_pattern.nums.push_back(value);
    }
}

Pattern Game::GetPattern()
{
    Pattern correct_answer;

    for (int value:correct_pattern.nums)
    {
        correct_answer.nums.push_back(value);
    }

    return correct_answer;
}

void Game::SetDifficulty(int new_difficulty)
{
    difficulty = new_difficulty; 
}

int Game::GetDifficulty()
{
    int diff = difficulty;
    
    return diff;
}

void Game::ResetTurn()
{
    turn_counter = 1; 
}

int Game::GetTurn()
{
    int turn;

    turn = turn_counter;

    return turn;
}

void Game::IncrementTurn()
{
    turn_counter++;
}


void Game::CalculateStats(Pattern current_guess)
{
    Stat_Pattern new_stat; 
    int value;
    int target;


    for (int index= 0; index < difficulty; index++)
    {
        value = current_guess.nums[index];
        target = correct_pattern.nums[index];
        if (target == value)
        {
            new_stat.correct_positions.push_back('o');
        }
        else if (find(correct_pattern.nums.begin(),correct_pattern.nums.end(),value) != correct_pattern.nums.end())
        {
            new_stat.correct_positions.push_back('-');
        }
        else 
        {
            new_stat.correct_positions.push_back('x');
        }
    }


    stats[turn_counter-1] = new_stat;
}

Stat_Pattern Game::GetStat(int index)
{
    Stat_Pattern current_stat;

    current_stat = stats[index];

    return current_stat;
}

void Game::ResetStat()
{
    for (int index = 0; index < 10; index++)
    {
        stats[index].correct_positions.clear();
    }
}

