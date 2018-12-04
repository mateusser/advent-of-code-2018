#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
	int start = 0;
	int input;

	while (scanf("%d", &input) != EOF) {
		start += input;
	}

	printf("\n%d\n\n", start);

	return 0;
}