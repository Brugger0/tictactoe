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
        Game::players_.push_back(Player(Game::SYMBOL_LIST[i]));
    }
}

void Game::playerMove (Player player, int x, int y)
{
    Game::board_.setElement(x, y, player.getSymbol());
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
    std::cout << this->boardStatus();
    std::cout << "\n";
    this->playerMove(players_[0],0,0);
    std::cout << this->boardStatus();
    std::cout << this->checkWin(players_[0],0,0) << "\n\n";
    this->playerMove(players_[1],1,0);
    std::cout << this->boardStatus();
    std::cout << this->checkWin(players_[1],1,0) << "\n\n";
    this->playerMove(players_[0],0,1);
    std::cout << this->boardStatus();
    std::cout << this->checkWin(players_[0],0,1) << "\n\n";
    this->playerMove(players_[1],1,1);
    std::cout << this->boardStatus();
    std::cout << this->checkWin(players_[1],1,1) << "\n\n";
    this->playerMove(players_[0],0,2);
    std::cout << this->boardStatus();
    std::cout << this->checkWin(players_[0],0,2) << "\n\n";

}

std::string Game::boardStatus()
{
    return Game::board_.toString();
}
