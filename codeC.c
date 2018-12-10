#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FABRIC_SIZE 1000

void countFabric (char fabric[FABRIC_SIZE][FABRIC_SIZE]);
void getStarts (char starts[10], int *startLine, int *startColumn);
void getSizes (char sizes[10], int *width, int *height);

int main (int argc, char *argv[]) {
  int i, j;
  char fabric[FABRIC_SIZE][FABRIC_SIZE];
  for (i = 0; i < FABRIC_SIZE; i++) {
    for (j = 0; j < FABRIC_SIZE; j++) {
      fabric[i][j] = '.';
    }
  }  

  char id[10], at[10], starts[10], size[10];
  i = 0;
  while (scanf("%s %s %s %s", id, at, starts, size) != EOF) {
    int startLine, startColumn;
    getStarts(starts, &startLine, &startColumn);

    int width, height;
    getSizes(size, &width, &height);

    int k, l;
    for (k = startLine; k < (startLine + width); k++) {
      for (l = startColumn; l < (startColumn + height); l++) {
        if (fabric[k][l] == '.') fabric[k][l] = '#';
        else if (fabric[k][l] == '#') fabric[k][l] = 'X';
      }
    }
    i++;
  }

  countFabric(fabric);

  return 0;
}

void countFabric (char fabric[FABRIC_SIZE][FABRIC_SIZE]) {
  int i, j;
  int sumP = 0;
  int sumH = 0;
  int sumX = 0;

  for (i = 0; i < FABRIC_SIZE; i++) {
    for (j = 0; j < FABRIC_SIZE; j++) {
      if (fabric[i][j] == '.') sumP++;
      else if (fabric[i][j] == '#') sumH++;
      else if (fabric[i][j] == 'X') sumX++;
    }
  }

  printf(".  %d\n", sumP);
  printf("#  %d\n", sumH);
  printf("X  %d\n", sumX);
  printf("TOTAL  %d\n", sumP + sumH + sumX);
}

void getStarts (char starts[10], int *startL, int *startC) {
  char stringL[5], stringC[5];
  int size = strlen(starts) - 1;

  char *splitPoint = strrchr(starts, ',');
  memcpy(stringL, starts, splitPoint - starts);
  *startL = atoi(stringL);

  splitPoint++; // ignore ',' char
  char *endPoint = strrchr(starts, ':');
  memcpy(stringC, splitPoint, endPoint - splitPoint);
  *startC = atoi(stringC);
}

void getSizes (char sizes[10], int *width, int *height) {
  char stringWidth[5], stringHeight[5];
  int size = strlen(sizes);

  char *splitPoint = strrchr(sizes, 'x');
  memcpy(stringWidth, sizes, splitPoint - sizes);
  stringWidth[splitPoint - sizes] = '\0';
  *width = atoi(stringWidth);

  splitPoint++; // ignore 'x' char
  memcpy(stringHeight, splitPoint, (&sizes[strlen(sizes)]) - splitPoint);
  stringHeight[(&sizes[strlen(sizes)]) - splitPoint] = '\0';
  *height = atoi(stringHeight);
}
