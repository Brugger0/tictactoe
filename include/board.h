#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

namespace game
{

    class Board
    {
        std::vector<std::vector<char>> tiles;

    public:
        static const int BOARD_SIZE;

        Board();
        std::string toString();
    };

}

#endif
