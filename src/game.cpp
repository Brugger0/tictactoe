#include <vector>
#include <iostream>
#include <game.h>
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

    return win_test;
}

void Game::startGame()
{
    bool game_finished = false;

    std::cout << this->boardStatus();
    std::cout << "\n";

    while (!game_finished)
    {
        for (int i=0; !game_finished && i<Game::NUM_OF_PLAYERS; i++)
        {
            int move_x, move_y;

            std::cin >> move_x;
            std::cin >> move_y;

            players_[i].playerMove(move_x, move_y);
            std::cout << this->boardStatus();
            game_finished = this->checkWin(players_[i], move_x, move_y);
        }
    }
}

std::string Game::boardStatus()
{
    return Game::board_.toString();
}
