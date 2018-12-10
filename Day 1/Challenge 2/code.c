#include <stdlib.h>
#include <stdio.h>

int hasValue (int value, int *vector, int vectorSize);

int main (int argc, char *argv[]) {
	int input;

	int inputLength = 1;
	int *inputs = (int *) malloc(inputLength * sizeof(int));

	int valuesLength = 1;
	int *values = (int *) malloc(valuesLength * sizeof(int));

	values[0] = 0;

	while (scanf("%d", &input) != EOF) {
		inputs[inputLength - 1] = input;
		inputs = (int *) realloc(inputs, ++inputLength * sizeof(int));
	}

	// remove garbage from scanf
	inputs = (int *) realloc(inputs, --inputLength * sizeof(int));

	int idx = 0;
	while (1) {
		int newVal = values[valuesLength - 1] + inputs[idx];

		if (hasValue(newVal, values, valuesLength)) {
			printf("\nFinal answer: %d\n\n", newVal);
			break;
		} else {
			values = (int *) realloc(values, ++valuesLength * sizeof(int));
			values[valuesLength - 1] = newVal;
			idx++;
			idx = idx % inputLength;
		}
	}

	free(inputs);
	free(values);

	return 0;
}

int hasValue (int value, int *vector, int vectorSize) {
	int i;
	for (i = 0; i < vectorSize; i++) {
		if (vector[i] == value) return 1;
	}

	return 0;
}
