#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <bits/pthreadtypes.h>

#define GRID_SIZE 1000
#define MAX_DAYS 1000
#define THREADS 8
#define SUSCEPTIBLE 0
#define ZOMBIE 1
#define REMOVED 2
#define P_INFECT 0.3
#define P_DEATH 0.1

int currentGrid[GRID_SIZE][GRID_SIZE];
int nextGrid[GRID_SIZE][GRID_SIZE];
pthread_barrier_t barrier;

typedef struct {
    int startRow;
    int endRow;
} ThreadData;

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

// Thread function to process rows for simulation
void *simulateZombieInfectionParallel(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    for (int day = 0; day < MAX_DAYS; day++) {
        for (int i = data->startRow; i <= data->endRow; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (currentGrid[i][j] == SUSCEPTIBLE) {
                    decide_S_to_ZorR(i, j);
                } else {
                    nextGrid[i][j] = currentGrid[i][j];
                }
            }
        }

        pthread_barrier_wait(&barrier);

        if (data->startRow == 0) { // Main thread updates the current grid
            for (int i = 0; i < GRID_SIZE; i++) {
                for (int j = 0; j < GRID_SIZE; j++) {
                    currentGrid[i][j] = nextGrid[i][j];
                }
            }
            if (day % 10 == 0) {
                outputWorld(day);
            }
        }

        pthread_barrier_wait(&barrier);
    }

    return NULL;
}

int main() {
    pthread_t threads[THREADS];
    ThreadData threadData[THREADS];
    pthread_barrier_init(&barrier, NULL, THREADS);

    initialiseWorld();

    int rowsPerThread = GRID_SIZE / THREADS;
    for (int i = 0; i < THREADS; i++) {
        threadData[i].startRow = i * rowsPerThread;
        threadData[i].endRow = (i == THREADS - 1) ? GRID_SIZE - 1 : (i + 1) * rowsPerThread - 1;
        pthread_create(&threads[i], NULL, simulateZombieInfectionParallel, &threadData[i]);
    }

    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&barrier);
    printf("Parallel simulation completed.\n");
    return 0;
}
