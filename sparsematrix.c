#include <stdio.h>

int main() {
    int sparseMatrix[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5}
    };

    int rows = 5;
    int cols = 5;

    int nonZeroCount = 0;

    // Count the number of non-zero elements in the sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Create arrays to store the non-zero values and their corresponding row and column indices
    int nonZeroValues[nonZeroCount];
    int rowIndices[nonZeroCount];
    int colIndices[nonZeroCount];

    int index = 0;

    // Populate the arrays with non-zero values and their indices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                nonZeroValues[index] = sparseMatrix[i][j];
                rowIndices[index] = i;
                colIndices[index] = j;
                index++;
            }
        }
    }

    // Print the sparse matrix
    printf("Sparse Matrix:\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d at (%d, %d)\n", nonZeroValues[i], rowIndices[i], colIndices[i]);
    }

    return 0;
}
//kush
