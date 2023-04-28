#include <stdio.h>
#include <stdlib.h>
//malloc: malloc(size_t, size) 사이즈 크기만큼의 메모리를 받아서 void pointer형태로 뱉어낸다.
//4칸의 메모리중 첫 번째 메모리가 malloc이 뱉어낸 메모리 값.
//
int main()
{
    int *p;
    p = (int*)malloc(5*sizeof(int));//20byte
    //p = (int*)calloc(5, sizeof(int)); // 두 번째 인자 크기의 값에 a개 만큼 쓰겠다.->(4bye 크기)int 자료형에 해당하는 크기를 5개 사용 -> 20바이트 사용.
    p = (int*)realloc(p, 5*sizeof(int) + 10 * sizeof(int));// 20byte -> 4byte로 다시 줄어든다.
    if(p == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
    *p = 100;
    printf("%d\n", *p);

    free(p);//쓸일없는 메모리 해제해주는 과정. if 반환을 안하면 문제 발생.
    //loop문에서 반환을 안하면 이 프로그램이 메모리 반환을 안하면 프로그램이 살아있는 동안 계속 메모리를 사용하게 된다.
    //반드시 malloc을 사용하면 free로 반환해주어야 한다.
    return 0;

}