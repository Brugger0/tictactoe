#include <vector>
#include <iostream>
#include <game/game.h>
using namespace game;

const int Game::NUM_OF_PLAYERS = 2;
const std::vector<char> Game::SYMBOL_LIST ({'X','O'});

Game::Game()
{
    for (int i = 0; i < NUM_OF_PLAYERS; i++)
    {
        Game::players_.push_back(Player(Game::SYMBOL_LIST[i],&board_));
    }
}

bool Game::checkWin (Player player, int x, int y)
{
    bool win_test = true;

    for (int i = 0; i < Board::BOARD_SIZE; i++)
    {
        if (Game::board_.getElement(x,i) != player.getSymbol())
            win_test = false;
    }

    if (win_test)
        return true;

    win_test = true;

    for (int i = 0; i < Board::BOARD_SIZE; i++)
    {
        if (Game::board_.getElement(i,y) != player.getSymbol())
            win_test = false;
    }

    if (win_test)
        return win_test;

    // First diagonal
    if (x == y)
    {
        win_test = true;

        for (int i = 0; i < Board::BOARD_SIZE; i++)
        {
            if (Game::board_.getElement(i,i) != player.getSymbol())
                win_test = false;
        }
    }

    if (win_test)
        return win_test;

    // Second diagonal
    if (x + y == Board::BOARD_SIZE - 1)
    {
        win_test = true;

        for (int i = 0; i < Board::BOARD_SIZE; i++)
        {
            if (Game::board_.getElement(i,Board::BOARD_SIZE-i-1) != player.getSymbol())
                win_test = false;
        }
    }

    return win_test;
}

void Game::startGame()
{
    bool game_finished = false;

    std::cout << "\n";

    while (!game_finished)
    {
        for (int i=0; !game_finished && i<Game::NUM_OF_PLAYERS; i++)
        {
            int move_x, move_y;

            std::cout << "\n\'" << players_[i].getSymbol() << "\' sadturn:\n";
            std::cout << this->boardStatus() << '\n';

            std::cin >> move_x;
            std::cin >> move_y;

            try
            {
                players_[i].playerMove(move_x, move_y);
                game_finished = this->checkWin(players_[i], move_x, move_y);
            }
            catch (std::string e)
            {
                std::cout << e;
                i--;
            }
        }
    }
    
    std::cout << this->boardStatus() << '\n';
}

std::string Game::boardStatus()
{
    return Game::board_.toString();
}
