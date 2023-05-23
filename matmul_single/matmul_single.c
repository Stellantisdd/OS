#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1000
int count = 0;
int count_num = 0;
double sum = 0;

void print_matrix(int matrix[][MAX_LEN], char *name);

int a_matrix[MAX_LEN][MAX_LEN];
int b_matrix[MAX_LEN][MAX_LEN];
int c_matrix[MAX_LEN][MAX_LEN];

int main()
{
	while(count != 5){
		int i, j, k;
		struct timespec start, stop;
		double proc_time;

		/* initialization */
		srandom((unsigned int)time(NULL));
		for(i = 0 ; i < MAX_LEN ; i++)				// i (Row)
		{
			for(j = 0 ; j < MAX_LEN ; j++)			// j (Column)
			{
				a_matrix[i][j] = random() % 10;
				b_matrix[i][j] = random() % 10;
			}
		}

		/* Calculation */
		clock_gettime(CLOCK_MONOTONIC, &start);
		for(i = 0 ; i < MAX_LEN ; i++)				// i (Row)
		{
			for(j = 0 ; j < MAX_LEN ; j++)			// j (Column)
			{
				c_matrix[i][j] = 0;

				for(k = 0 ; k < MAX_LEN ; k++)
				{
					c_matrix[i][j] += a_matrix[i][k] * b_matrix[k][j];
				}
			}
		}
		clock_gettime(CLOCK_MONOTONIC, &stop);

		proc_time = (double)(stop.tv_sec - start.tv_sec);
		proc_time += ((double)(stop.tv_nsec - start.tv_nsec) / 1000000000);

		// print_matrix(a_matrix, "A");
		// print_matrix(b_matrix, "B");
		// print_matrix(c_matrix, "C");

		printf("\nProcessing time [%d]: %fs",count+1, proc_time);
        sum += proc_time;
        count_num += 1;
        count += 1;
	}
	printf("\n\n Avg_time: %fs\n", sum/count_num);
	return 0;
}

void print_matrix(int matrix[][MAX_LEN], char *name)
{
	int i, j;

	printf("========== %s matrix ==========\n", name);
	for(i = 0 ; i < MAX_LEN ; i++)				// i (Row)
	{
		for(j = 0 ; j < MAX_LEN ; j++)			// j (Column)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

