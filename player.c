#include "player.h"
#include "maze.h"

int moveCount = 0;

void movePlayer(int maze[][5], int* x, int* y, char direction) {
    int newX = *x;
    int newY = *y;

    switch (direction) {
        case 'W':
            newX--;
            break;
        case 'S':
            newX++;
            break;
        case 'A':
            newY--;
            break;
        case 'D':
            newY++;
            break;
    }

    if (isValidMove(maze, newX, newY, direction)) {
        *x = newX;
        *y = newY;
        moveCount++;
    }
}

int hasWon(int x, int y) {
    return (x == 4 && y == 4);
}

int getValidMoveCount() {
    return moveCount;
}
