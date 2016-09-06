#include <string>
#include <game/player.h>
using namespace game;

Player::Player(char symbol, Board *board): symbol_(symbol), board_(board)
{}

char Player::getSymbol()
{
    return symbol_;
}

void Player::playerMove(int x, int y)
{
    if (board_->getElement(x,y) != '-')
        throw std::string("Invalid move (tile already occupied)\n");

    this->board_->setElement(x, y, this->getSymbol());
}
