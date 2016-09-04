#ifndef PLAYER_H
#define PLAYER_H

#include <board.h>

namespace game
{
    
    class Player
    {
    private:
        char symbol_;
        Board *board_;

    public:
        Player(char symbol, Board *board);

        char getSymbol();

        void playerMove(int x, int y);
    };

}

#endif
