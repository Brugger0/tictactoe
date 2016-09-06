#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <game/board.h>
#include <game/player.h>

namespace game
{

    class Game
    {
    private:
        Board board_;
        std::vector<Player> players_;

    public:
        static const int NUM_OF_PLAYERS;
        static const std::vector<char> SYMBOL_LIST;

        Game();

        bool checkWin(Player player, int x, int y);

        void startGame();

        std::string boardStatus();

    };

}

#endif
