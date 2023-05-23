#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int mat_mul(int** src1, int** src2, int** dst, int len)
{
    int i, j, k;
    int result = 0;

    for (i = 0; i < len; i++){ // i (Row)
        for (j = 0; j < len; j++){ // j (Column)
            //c[i][j] = a[i][j] + b[i][j] //add matrix
            result = 0;
            for (k = 0; k < len; k++){ 
                result += src1[i][k] * src2[k][j]; //matrixx multiplication
            }
            dst[i][j] = result;
        }
    }
    return 0;
}

typedef struct {
    int i;
    int f;
    int** src1;
    int** src2;
    int** dst;
    int len;
} matmul_arg_t;

//int mat_mul_th_kernel(int i, int** src1, int** src2, int** dst, int len)
void *mat_mul_th_kernel(void *arg)
{
    int             j, k, result;
    matmul_arg_t    *parg = (matmul_arg_t*)arg;
    int             i = parg->i;
    int             f = parg->f;
    int             **src1 = parg->src1;
    int             **src2 = parg->src2;
    int             **dst = parg->dst;
    int             len = parg->len;

    //printf("Thread %d is started\n", i);//thread test code
    for (i; i<= f;i++){
        for (j = 0; j < len; j++){ // j (Column)
            //c[i][j] = a[i][j] + b[i][j] //add matrix
            result = 0;
            for (k = 0; k < len; k++){ 
                result += src1[i][k] * src2[k][j]; //matrixx multiplication
            }
            dst[i][j] = result;
        }
    }
}
int mat_mul_th(int** src1, int** src2, int** dst, int len)
{
    int i, j, k, res;
    matmul_arg_t *arg;
    pthread_t *a_thread;
    void *thread_result;

    a_thread = (pthread_t*)malloc(sizeof(pthread_t) * 12);//pthread type의 크기 만큼 * len 갯수만큼.
    //len이 10이면 10개, len이 100이면 100개가 만들어진다.
    for (i = 0; i < len ; i = i + 100){ // i (Row) i기준으로 thread가 만들어지게 된다. 속도를 높이기 위해서
    //행단위와 코어 갯수 단위에 따른 계산 속도의 차이가 나타난다. 만들어볼것.
        int f = i;
        arg = (matmul_arg_t*)malloc(sizeof(matmul_arg_t));
        arg->i = i; //행번호죠.
        arg->f = f+99;//끝행번호.
        arg->src1 = src1;
        arg->src2 = src2;
        arg->dst = dst;
        arg->len = len;
        //mat_mul_th_kernel((void*)&arg);
        //printf("Thread %d is called\n", i); thread test code
        res = pthread_create(a_thread + i/100, NULL, mat_mul_th_kernel, (void*)arg);

        if (res != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    
    for (i=0; i < 12; i++) {
        res = pthread_join(a_thread[i], &thread_result);
        if(res != 0){
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}

// 0: Success
// 1: Inverse matrix isn't existed.
int mat_inv(int** src, int** dst, int)
{

}
