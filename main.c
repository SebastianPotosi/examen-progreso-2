#include <stdio.h>
#include "maze.h"
#include "player.h"

void printMenu() {
    printf("Bienvenido al juego del laberinto!\n");
    printf("1. Jugar\n");
    printf("2. Creditos\n");
    printf("3. Salir\n");
}

void printCredits() {
    printf("Desarrollado por [tu nombre]\n");
}

void juegoNuevo() {
    int maze[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0}
    };

    int x = 0, y = 0;
    char move;
    int won = 0;

    printf("Laberinto inicial:\n");
    printMaze(maze);

    printf("Posicion actual: (%d, %d)\n", x, y);

    while (!won) {
        printf("Ingresa tu movimiento (WASD): ");
        scanf(" %c", &move);

        movePlayer(maze, &x, &y, move);
        won = hasWon(x, y);

        printf("Laberinto:\n");
        printMaze(maze);

        printf("Posicion actual: (%d, %d)\n", x, y);

        if (won) {
            int validMoves = getValidMoveCount();
            printf("Ganaste!\n");

            if (validMoves <= 8) {
                printf("Eres un Pro!\n");
            } else if (validMoves <= 15) {
                printf("Eres novato\n");
            } else {
                printf("Eres un noob!\n");
            }
        }
    }
}

int main() {
    int choice = 0;

    while (choice != 3) {
        printMenu();
        printf("Ingresa tu opcion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                juegoNuevo();
                break;
            case 2:
                printCredits();
                break;
            case 3:
                printf("Gracias por jugar!\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intenta nuevamente.\n");
                break;
        }
    }

    return 0;
}
