#include <board.h>
#include <player.h>
#include <iostream>

int main()
{
    game::Board myBoard;
    game::Player player_one('X');

    myBoard.setElement(0,1,player_one.getSymbol());

    std::cout << myBoard.toString();

    return 0;
}
