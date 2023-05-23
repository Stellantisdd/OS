#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_LEN 1500
int count = 0;
int count_num = 0;
double sum = 0;
void *matmul_row(void *row); //thread가 실행할 함수. 매개변수로 row값을 받는다. 받은 row값을 토대로 아 몇 번째 행 계산이구나 인지.
void print_matrix(int matrix[][MAX_LEN], char *name);

int a_matrix [MAX_LEN][MAX_LEN];
int b_matrix [MAX_LEN][MAX_LEN];
int c_matrix [MAX_LEN][MAX_LEN];

sem_t bin_sem;

int main()
{
    while(count != 5){
        int i, j;
        struct timespec start, stop;
        double proc_time;//소수점 까지 표현 가능한 type으로 만듦.
        //그냥 clock 사용시 thread마다의 시간들을 다 count함. 따라서 timespec 사용.
        
        int res;
        pthread_t a_thread[MAX_LEN];
        int a_thread_row;
        void *thread_result;

        /* initialization*/
        srandom((unsigned int)time(NULL));
        for(i = 0; i < MAX_LEN; i++)        // i (ROW)
        {
            for(j = 0; j < MAX_LEN; j++)     // j (COLUMN)
            {
                a_matrix[i][j] = random() % 10;
                b_matrix[i][j] = random() % 10;
            }
        }

        res = sem_init(&bin_sem, 0, 1);
        if(res != 0)
        {
            perror("Semaphore initialization failed");
            exit(EXIT_FAILURE);
        }
    //    
        /* Calculation */
        clock_gettime(CLOCK_MONOTONIC, &start);//clock문제 해결 위해 clock)gettime사용.
        for(i=0; i < MAX_LEN; i++)     // i (ROW)
        {
            sem_wait(&bin_sem); // 주 목적은 sync sync맞추는 것 굉장히 중요!
            a_thread_row = i; // 몇 번 행에서 시작. 공유변수. 생성된 thread가 얘를 읽고 post하기 까지 기다린다.

            res = pthread_create(&a_thread[i], NULL, matmul_row, (void*)&a_thread_row);
            if(res != 0)
            {
                perror("Thread creation failed");
                exit(EXIT_FAILURE);
            }
        }
    //
        for(i = 0; i < MAX_LEN; i++)     // i (ROW)
        {
            res = pthread_join(a_thread[i], &thread_result);
            if(res != 0)
            {
                perror("Thread join failed");
                exit(EXIT_FAILURE);
            }
        }//여기까지가 matrix 곱셈. 여기서 끝.
        clock_gettime(CLOCK_MONOTONIC, &stop);//s와 ns단위 두개 다 존재.

        proc_time = (double)(stop.tv_sec - start.tv_sec);
        proc_time += ((double)(stop.tv_nsec - start.tv_nsec) / 1000000000);
        //더 자세한 값을 얻기위해서 s와 ns를 다 더해준다. 

        /* Check */
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
//
void *matmul_row(void * row)//1:39:00
{
    int mat_row;
    int i, j;

    mat_row = *((int *)row);     //지역변수에다가 값을 받아서 저장해서 하겠다. 계산 분할 -> 성능 감소 but 안정성 증가.
    sem_post(&bin_sem);          //읽기 완료 후 sempost 해준다.
    //89 line까지가 내가 계산해야하는 행을 mat_row에 저장. 이제 element하나하나 계산 시작.
    for(i = 0; i < MAX_LEN; i++)
    {
        c_matrix[mat_row][i] = 0; //c_matrix값 0으로 초기화.
        for(j = 0; j < MAX_LEN; j++)
        {
            c_matrix[mat_row][i] += a_matrix[mat_row][j] * b_matrix[j][i];//곱하고 더하는 과정 반복.
        }
    }
    //한 행에 대한 연상 끝.
    pthread_exit("Thank you for CPU time"); // 한 행에 대한 연산 종류 이후 thread 종료.
}
//
void print_matrix(int matrix[][MAX_LEN], char *name)//matrix 출력.
{
    int i, j;
    
    printf("========== %s matrix ==========\n", name);
    for(i = 0; i < MAX_LEN; i++)            // i (ROW)
    {
        for(j = 0; j < MAX_LEN ; j++)       // j (COLUMN)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}