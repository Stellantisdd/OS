#include <stdio.h>
//const: 상수로 만들어 준다. const int b로 b에 값을 입력하면 이후에 값에 대입이 불가능.
//static: 함수 내에서 함수가 다시 호출 되었을 때 선언하지 않는다. -> 메모리에 값이 남아 있다.
// gcc '파일명'
//./a.out으로 실행
//gcc 02_condition.c -o test -> test로 이름지정해서 실행 가능해짐.
// ./test
int main()
{
//int i, j;

//for (j = 0; j < 6; j++){
//    for(i = j; i < 6; i++){
//        printf("*");
//    }
//    printf("\n");
        // int a = 5;
        // int *a_p = &a;
        // int **a_pp = &a_p;

        // printf("a value: %d\n", a);

        // printf("a address: %p\n", &a);
        // printf("a_p address %p\n", &a_p);
        // printf("a_pp address: %p\n", &a_pp);

        // printf("%p\n", *a_pp); //a_p의 값 = a의 주소
        // printf("%d\n", **a_pp); //a_p의 값 = a의 값


        // return 0;
        // }
        //ls: 현재 디렉토리 파일 목록 출력
        //cd ${a}: a 디렉토리로 이동
        //mkdrir ${~~~}: ~~~디렉토리 생성
        // --- .: 현재 디렉토리
        // --- ..: 상위 디렉토리
    int a[2][3] = {2, 3, 4, 5, 6, 7};

    void *p = a;
    void *p_a = &a;

    printf("%p\n", p);
    printf("%p\n", p+1);
    printf("%p\n", (int*)p+1);//(int*) +4되고, (double*)로 하는 경우 + 8된다.
    printf("0x%d\n", *(int*)(p+1)); //괄호따라서 pointer가 계산될 때 어떻게 계산되느냐.
    
// 0x0000_0002 <<< pointer가 
// 0x0000_0003
    return 0;    
}