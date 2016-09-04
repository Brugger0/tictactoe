#include <player.h>
using namespace game;

Player::Player(char symbol): symbol_(symbol)
{}

char Player::getSymbol()
{
    return symbol_;
}
