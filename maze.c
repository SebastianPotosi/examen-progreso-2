#include "maze.h"
#include <stdio.h>

void printMaze(int maze[][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (maze[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int isValidMove(int maze[][5], int x, int y, char direction) {
    switch (direction) {
        case 'W':
            if (x > 0 && maze[x - 1][y] == 0)
                return 1;
            break;
        case 'S':
            if (x < 4 && maze[x + 1][y] == 0)
                return 1;
            break;
        case 'A':
            if (y > 0 && maze[x][y - 1] == 0)
                return 1;
            break;
        case 'D':
            if (y < 4 && maze[x][y + 1] == 0)
                return 1;
            break;
    }
    return 0;
}

