#ifndef PLAYER_H
#define PLAYER_H

namespace game
{
    
    class Player
    {
    private:
        char symbol_;

    public:
        Player(char symbol);

        char getSymbol();
    };

}

#endif
