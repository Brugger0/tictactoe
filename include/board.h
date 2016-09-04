#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

namespace game
{

    class Board
    {
    private:
        std::vector<std::vector<char>> tiles_;

    public:
        static const int BOARD_SIZE;

        Board();

        void setElement(int x, int y, char value);
        char getElement(int x, int y);

        std::string toString();
    };

}

#endif
