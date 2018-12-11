#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRID_SIZE 500 // we know the range of the coordinates
#define TOTAL_INPUTS 50 // we know there are only 50 inputs
#define MAX_SUM_DISTANCE 10000

typedef struct {
  int x, y;
} Coordinate;

int manhattanDistance (int x1, int y1, int x2, int y2);
int countGrid (int grid[GRID_SIZE][GRID_SIZE]);

int main (int argc, char *argv[]) {
  int i, j, k;
  int grid[GRID_SIZE][GRID_SIZE];

  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = 0;
    }
  }

  // read inputs
  Coordinate locations[TOTAL_INPUTS];
  char skip; // it's not a hack if it works
  int x, y;
  for (i = 0; i < TOTAL_INPUTS; i++) {
    scanf("%d %c %d", &x, &skip,&y);
    locations[i].x = x;
    locations[i].y = y;
  }

  // get the coordinate sum of all distances
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      int sumDistance = 0;
      for (k = 0; k < TOTAL_INPUTS; k++) {
        sumDistance += manhattanDistance(i, j, locations[k].x, locations[k].y);
      }
      if (sumDistance < MAX_SUM_DISTANCE) grid[i][j] = 1;
    }
  }

  printf("Sum: %d", countGrid(grid));

  printf("\n");

  return 0;
}

int manhattanDistance (int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int countGrid (int grid[GRID_SIZE][GRID_SIZE]){
  int i, j, sum = 0;
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j]) sum++;
    }
  }

  return sum;
}
