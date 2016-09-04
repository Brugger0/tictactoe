#include <player.h>
using namespace game;

Player::Player(char symbol, Board *board): symbol_(symbol), board_(board)
{}

char Player::getSymbol()
{
    return symbol_;
}

void Player::playerMove(int x, int y)
{
    board_->setElement(x, y, this->getSymbol()); }
