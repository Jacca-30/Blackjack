#include "Game.h"
#include <iostream>

int main() {
    Game game;
    char again = 'y';
    while (again == 'y' || again == 'Y') {
        game.startRound();
        std::cout << std::endl << "Play again? (y/n): ";
        std::cin >> again;
    }
    return 0;
}
