#include "map.h"

template <class T>
int getLen(T& array)
{
return (sizeof(array) / sizeof(array[0]));
}

Map::Map() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            this->gameArr[i][j] = 0;
        }
    }
    this->score = 0;
}

void Map::generateNewNum() {
    srand((unsigned)time(NULL));
    if (!this->hasSpace()) return;
    int x;
    int y;
    do {
        x = rand() % ROW;
        y = rand() % COL;
    } while (this->gameArr[x][y] != 0);
    this->gameArr[x][y] = rand() % 2 == 0 ? 2 : 4;
}

void Map::printColor(int num) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | findColor[num]);
    cout << to_string(num);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
}

void Map::showMap() {
    cout << "©³©¥©¥©¥©¥©¥©×©¥©¥©¥©¥©¥©×©¥©¥©¥©¥©¥©×©¥©¥©¥©¥©¥©·" << endl;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            cout << "©§";
            if ((gameArr[i][j]) == 0) cout << setw(5) << setfill(' ') << "-";
            else {
                cout << setw(5) << setfill(' ');
                printColor(gameArr[i][j]);
            }
        }
        cout << "©§" << endl;
        if (i == COL - 1) {
            cout << "©»©¥©¥©¥©¥©¥©ß©¥©¥©¥©¥©¥©ß©¥©¥©¥©¥©¥©ß©¥©¥©¥©¥©¥©¿" << endl;
        }
        else cout << "©Ç©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©ï©¥©¥©¥©¥©¥©Ï" << endl;
    }
}

void Map::gameTip() {
    cout << "W: Up    "
         << "S: Down    "
         << "A: Left    "
         << "D: Right   " << endl
         << "R: Restart    Q: Exit" << endl;
}

void Map::showScroe() {
    cout << "Score: " << this->score << endl;
}

bool Map::hasSpace() {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (this->gameArr[i][j] == 0) return true;
        }
    }
    return false;
}

bool Map::winGame() {
    // test the highestNum
    //cout << this->highestNum;
    if (this->highestNum == 64) {
        return true;
    }
    else {
        return false;
    }
}

void Map::moveleft() {
    for (int i = 0; i < ROW; ++i) {
        // move left, the left side doesnt need to move
        for (int k = 0, j = 1; j < COL; ++j) {
            if (gameArr[i][j] != 0) {
                if (gameArr[i][k] == gameArr[i][j]) {
                    this->score += gameArr[i][k];
                    gameArr[i][k] *= 2;
                    this->highestNum = max(highestNum, gameArr[i][k]);
                    gameArr[i][j] = 0;
                    k++;
                    moveOnce = true;
                }
                // move the find num into k position
                else if (gameArr[i][k] == 0) {
                    gameArr[i][k] = gameArr[i][j];
                    gameArr[i][j] = 0;
                    moveOnce = true;
                }
                // move the find num into k + 1 position
                else {
                    gameArr[i][++k] = gameArr[i][j];
                    if (k != j) {
                        gameArr[i][j] = 0;
                        moveOnce = true;
                    }
                }
            }
        }
    }
}

void Map::moveUp() {
    for (int i = 0; i < COL; ++i) {
        // move up, the top side doesnt need to move
        for (int k = 0, j = 1; j < ROW; ++j) {
            if (gameArr[j][i] != 0) {
                if (gameArr[k][i] == gameArr[j][i]) {
                    this->score += gameArr[k][i];
                    gameArr[k][i] *= 2;
                    this->highestNum = max(highestNum, gameArr[k][i]);
                    gameArr[j][i] = 0;
                    k++;
                    moveOnce = true;
                }
                // move the find num into k position
                else if (gameArr[k][i] == 0) {
                    gameArr[k][i] = gameArr[j][i];
                    gameArr[j][i] = 0;
                    moveOnce = true;
                }
                // move the find num into k + 1 position
                else {
                    gameArr[++k][i] = gameArr[j][i];
                    if (k != j) {
                        gameArr[j][i] = 0;
                        moveOnce = true;
                    }
                }
            }
        }
    }
}

void Map::moveRight() {
    for (int i = 0; i < COL; ++i) {
        // move right, the rightest side doesnt need to move
        for (int k = ROW - 1, j = ROW - 2; j >= 0; --j) {
            if (gameArr[i][j] != 0) {
                if (gameArr[i][k] == gameArr[i][j]) {
                    this->score += gameArr[i][k];
                    gameArr[i][k] *= 2;
                    this->highestNum = max(highestNum, gameArr[i][k]);
                    gameArr[i][j] = 0;
                    k--;
                    moveOnce = true;
                }
                // move the find num into k position
                else if (gameArr[i][k] == 0) {
                    gameArr[i][k] = gameArr[i][j];
                    gameArr[i][j] = 0;
                    moveOnce = true;
                }
                // move the find num into k - 1 position
                else {
                    gameArr[i][--k] = gameArr[i][j];
                    if (k != j) {
                        gameArr[i][j] = 0;
                        moveOnce = true;
                    }
                }
            }
        }
    }
}

void Map::moveDown() {
    for (int i = 0; i < COL; ++i) {
        // move down, the bottom side doesnt need to move
        for (int k = ROW - 1, j = ROW - 2; j >= 0; --j) {
            if (gameArr[j][i] != 0) {
                if (gameArr[k][i] == gameArr[j][i]) {
                    this->score += gameArr[k][i];
                    gameArr[k][i] *= 2;
                    this->highestNum = max(highestNum, gameArr[k][i]);
                    gameArr[j][i] = 0;
                    k--;
                    moveOnce = true;
                }
                // move the find num into k position
                else if (gameArr[k][i] == 0) {
                    gameArr[k][i] = gameArr[j][i];
                    gameArr[j][i] = 0;
                    moveOnce = true;
                }
                // move the find num into k + 1 position
                else {
                    gameArr[--k][i] = gameArr[j][i];
                    if (k != j) {
                        gameArr[j][i] = 0;
                        moveOnce = true;
                    }
                }
            }
        }
    }
}
