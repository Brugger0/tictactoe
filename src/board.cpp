#include <string>
#include <vector>
#include <board.h>
using namespace game;

const int Board::BOARD_SIZE = 3;

Board::Board() : tiles(Board::BOARD_SIZE, std::vector<char>(Board::BOARD_SIZE, 'b'))
{
    for (int i = 0; i < Board::BOARD_SIZE; i++)
        for (int j = 0; j < Board::BOARD_SIZE; j++)
            Board::tiles[i][j] = 'a' + i*Board::BOARD_SIZE + j;
}

std::string Board::toString()
{
    std::string board_string;

    for (int i = 0; i < Board::BOARD_SIZE; i++)
    {
        for (int j = 0; j < Board::BOARD_SIZE; j++)
        {
            board_string.push_back(Board::tiles[i][j]);
            board_string.append(" ");
        }

        board_string.append("\n");
    }

    return board_string;
}
