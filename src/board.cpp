#include <string>
#include <vector>
#include <board.h>
using namespace game;

const int Board::BOARD_SIZE = 3;

Board::Board() : tiles_(Board::BOARD_SIZE, std::vector<char>(Board::BOARD_SIZE, '-'))
{}

void Board::setElement (int x, int y, char value)
{
    Board::tiles_[x][y] = value;
}

char Board::getElement (int x, int y)
{
    return Board::tiles_[x][y];
}

std::string Board::toString()
{
    std::string board_string;

    for (int i = 0; i < Board::BOARD_SIZE; i++)
    {
        for (int j = 0; j < Board::BOARD_SIZE; j++)
        {
            board_string.push_back(Board::tiles_[i][j]);
            board_string.append(" ");
        }

        board_string.append("\n");
    }

    return board_string;
}
