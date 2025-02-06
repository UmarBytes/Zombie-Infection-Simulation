#include <stdio.h>

#include <stdlib.h>

#include <time.h>



#define GRID_SIZE 1000

#define MAX_DAYS 1000

#define SUSCEPTIBLE 0

#define ZOMBIE 1

#define REMOVED 2

#define P_INFECT 0.3

#define P_DEATH 0.1



int currentGrid[GRID_SIZE][GRID_SIZE];

int nextGrid[GRID_SIZE][GRID_SIZE];



// Initialize the grid with all cells as SUSCEPTIBLE and one ZOMBIE

void initialiseWorld() {

    for (int i = 0; i < GRID_SIZE; i++) {

        for (int j = 0; j < GRID_SIZE; j++) {

            currentGrid[i][j] = SUSCEPTIBLE;

        }

    }

    currentGrid[GRID_SIZE / 2][GRID_SIZE / 2] = ZOMBIE;

}



// Output the grid to a file for visualization

void outputWorld(int day) {

    char filename[50];

    sprintf(filename, "grid_day_%d.txt", day);

    FILE *file = fopen(filename, "w");

    for (int i = 0; i < GRID_SIZE; i++) {

        for (int j = 0; j < GRID_SIZE; j++) {

            fprintf(file, "%d ", currentGrid[i][j]);

        }

        fprintf(file, "\n");

    }

    fclose(file);

}



// Count the number of neighboring ZOMBIE cells

int countZombieNeighbours(int x, int y) {

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int count = 0;

    for (int k = 0; k < 8; k++) {

        int nx = (x + dx[k] + GRID_SIZE) % GRID_SIZE;

        int ny = (y + dy[k] + GRID_SIZE) % GRID_SIZE;

        if (currentGrid[nx][ny] == ZOMBIE) {

            count++;

        }

    }

    return count;

}



// Decide state change for SUSCEPTIBLE cells

void decide_S_to_ZorR(int x, int y) {

    int zombieNeighbors = countZombieNeighbours(x, y);

    float randomValue = rand() / (float)RAND_MAX;



    if (randomValue < P_INFECT * zombieNeighbors) {

        nextGrid[x][y] = ZOMBIE;

    } else if (randomValue < P_DEATH) {

        nextGrid[x][y] = REMOVED;

    } else {

        nextGrid[x][y] = SUSCEPTIBLE;

    }

}



// Copy the nextGrid into currentGrid

void copyNextGridToCurrent() {

    for (int i = 0; i < GRID_SIZE; i++) {

        for (int j = 0; j < GRID_SIZE; j++) {

            currentGrid[i][j] = nextGrid[i][j];

        }

    }

}



// Simulate the zombie infection for multiple days

void simulateZombieInfection() {

    for (int day = 0; day < MAX_DAYS; day++) {

        for (int i = 0; i < GRID_SIZE; i++) {

            for (int j = 0; j < GRID_SIZE; j++) {

                if (currentGrid[i][j] == SUSCEPTIBLE) {

                    decide_S_to_ZorR(i, j);

                } else {

                    nextGrid[i][j] = currentGrid[i][j];

                }

            }

        }

        copyNextGridToCurrent();

        if (day % 10 == 0) {

            outputWorld(day);

        }

    }

}



int main() {

    srand(time(NULL));

    initialiseWorld();

    simulateZombieInfection();

    printf("Simulation completed.\n");

    return 0;

}
