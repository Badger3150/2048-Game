#include <iostream>
#include "map.h"


using namespace std;

int main()
{
    Map game;
    game.showMap();
    bool finish = false;
    while (!game.winGame() && (game.hasSpace() || game.moveOnce) && !finish) {
        game.showScroe();
        game.generateNewNum();
        game.gameTip();
        game.moveOnce = false;
        if (!_kbhit()) {
            int input = _getch();
            switch (input) {
            case 65:
            case 97:
                game.moveleft();
                break;
            case 87:
            case 119:
                game.moveUp();
                break;
            case 68:
            case 100:
                game.moveRight();
                break;
            case 83:
            case 115:
                game.moveDown();
                break;
            // quit the game
            case 81:
            case 113:
                finish = true;
                break;
            default:
                game.moveOnce = true;
                break;
            }
        }
        system("cls");
        game.showMap();
    }
    if (game.winGame()) {
        cout << "Congratulations, your score is " << game.score << endl;
    }
    else if (!game.moveOnce) {
        cout << "Sorry, there is no way to move." << endl;
    }
    else {
        cout << "Looking forward to your next try" << endl;
    }
    return 0;
}
