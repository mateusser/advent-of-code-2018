#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRID_SIZE 500 // we know the range of the coordinates
#define TOTAL_INPUTS 50 // we know there are only 50 inputs

typedef struct {
  int x, y;
} Coordinate;

int manhattanDistance (int x1, int y1, int x2, int y2);
int hasValue(int value, int *v, int vSize);

int main (int argc, char *argv[]) {
  int i, j, k;
  int grid[GRID_SIZE][GRID_SIZE];

  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = -10;
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

  // getting nearest locations for all points
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      int minDistance = 250000;
      int minId = -1;
      for (k = 0; k < TOTAL_INPUTS; k++) {
        int distance = manhattanDistance(i, j, locations[k].x, locations[k].y);
        if (distance == minDistance) {
          minId = -1;
        } else if (distance < minDistance) {
          minDistance = distance;
          minId = k;
        }
      }
      grid[i][j] = minId;
      // printf("x: %3d    y: %3d    grid: %3d\n", i, j, grid[i][j]);
    }
  }

  // count areas
  int areas[TOTAL_INPUTS];
  for (i = 0; i < TOTAL_INPUTS; i++) {
    areas[i] = 0;
  }

  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j] < TOTAL_INPUTS && grid[i][j] >= 0) {
        areas[grid[i][j]]++;
      }
    }
  }

  printf("Areas: ");
  for (i = 0; i < TOTAL_INPUTS; i++) {
    printf("%d, ", areas[i]);
  }

  // get infinite areas, or the one that appear or borders
  int excludedSize = 0;
  int *excluded = (int *) malloc(excludedSize * sizeof(int));

  // top border
  for (i = 0; i < GRID_SIZE; i++) {
    if (!hasValue(grid[0][i], excluded, excludedSize) && grid[0][i] != -1) {
      excluded = (int *) realloc(excluded, ++excludedSize * sizeof(int));
      excluded[excludedSize - 1] = grid[0][i];
    }
  }

  // right border
  for (i = 0; i < GRID_SIZE; i++) {
    if (!hasValue(grid[i][0], excluded, excludedSize) && grid[i][0] != -1) {
      excluded = (int *) realloc(excluded, ++excludedSize * sizeof(int));
      excluded[excludedSize - 1] = grid[i][0];
    }
  }

  // bottom border
  for (i = 0; i < GRID_SIZE; i++) {
    if (!hasValue(grid[GRID_SIZE - 1][i], excluded, excludedSize) && grid[GRID_SIZE - 1][i] != -1) {
      excluded = (int *) realloc(excluded, ++excludedSize * sizeof(int));
      excluded[excludedSize - 1] = grid[GRID_SIZE - 1][i];
    }
  }

  // left border
  for (i = 0; i < GRID_SIZE; i++) {
    if (!hasValue(grid[i][GRID_SIZE - 1], excluded, excludedSize) && grid[i][GRID_SIZE - 1] != -1) {
      excluded = (int *) realloc(excluded, ++excludedSize * sizeof(int));
      excluded[excludedSize - 1] = grid[i][GRID_SIZE - 1];
    }
  }

  printf("\n\nExcluded: ");
  for (i = 0; i < excludedSize; i++) {
    printf("%d, ", excluded[i]);
  }

  printf("\n");

  free(excluded);

  return 0;
}

int manhattanDistance (int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int hasValue(int value, int *v, int vSize) {
  int i;
  for (i = 0; i < vSize; i++) {
    if (v[i] == value) return 1;
  }

  return 0;
}
