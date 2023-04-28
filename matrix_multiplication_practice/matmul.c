#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void print_matrix(int**, char*, int);

int main(int argc, char** argv)
{
    int **a;
    int **b;
    int **c;
    int i, j, k;
    int len;
    clock_t start, stop;

    if (argc == 2) {
        len = atoi(argv[1]);
    } else {
        len = 10;
    }

    a = (int**)malloc(len * sizeof(int*));
    b = (int**)malloc(len * sizeof(int*));
    c = (int**)malloc(len * sizeof(int*));

    for (i = 0; i < len; i++) {
        a[i] = (int*)malloc(len* sizeof(int));
        b[i] = (int*)malloc(len * sizeof(int));
        c[i] = (int*)malloc(len * sizeof(int));
    }

    srandom((unsigned int)time(NULL));
    for (i = 0; i < len; i++) { // i (Row)
        for (j = 0; j < len; j++) { // j (Column)
            a[i][j] = random() % 10;
            b[i][j] = random() % 10;
        }
    }   
printf("TEST\n");
    start = clock();

    if (mat_mul(a, b, c, len) != 0) {
        fprintf(stderr, "Failed to Matrix multiplication");
        exit(1);
    }
    
    stop = clock();

    print_matrix(a, "A", len);
    print_matrix(b, "B", len);
    print_matrix(c, "C", len);

    printf("Processing time: %f\n", ((double)stop - start)/CLOCKS_PER_SEC);
    return 0;
}

void print_matrix(int** matrix, char* name, int len)
{
    printf("== %s matrix ====================\n", name);
    for (int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

