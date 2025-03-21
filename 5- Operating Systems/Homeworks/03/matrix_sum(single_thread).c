#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 100
#define COLS 100

int matrix[ROWS][COLS];
int thread[ROWS];
int m = 100;
int n = 100;

int main() {
    // initialize matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // start time
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // calculate sum of matrix
    int total_sum = 0;
    for (int row = 0; row < m; row++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[row][j];
        }
        thread[row] = sum;
    }
    for (int i = 0; i < m; i++) {
        total_sum += thread[i];
    }

    // end time
    double elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
    printf("elapsed time: %f seconds\n", elapsed_time);

    return 0;
}
