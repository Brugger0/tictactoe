#include <game.h>

int main()
{
    /*
    game::Board myBoard;
    game::Player player_one('X');

    myBoard.setElement(0,1,player_one.getSymbol());

    std::cout << myBoard.toString();
    */

    game::Game game;
    game.startGame();

    return 0;
}
