#include <stdio.h>
#include <stdlib.h>

int* sum(int, int);
int main(){
    int a = 5;
    int b = 9;
    int *c = sum(a, b);

    printf("result: %d\n", *c);
    //free(c);//그 주소에 있는 동적할당된 메모리를 제거.
}

int* sum(int a, int b){
    //int* result = (int*)malloc(sizeof(int));
    static int result;
    result = a + b;
    return &result;
}
//segmentaion fault: 함수가 끝나면 그 변수에 접근할 수 없어서 주소 출력 불가. 그런데 result에 있는 주소 값을 return 줘서 출력할려 함.
//일반 변수는 변수가 늘어나면 위에서 부터 자리나고 동적 메모리 (malloc)은 아래에서 부터 자리난다. 그래서 자라다보면 오류가 발생할 수 있음.
//static은 상수라는 다른영역에 이미 할당되어 있다.
//thread_function을 작성해야 하는데, 이 함수를 작성가능한게 malloc밖에 없다. void pointer형 매개변수를 변수로 받음.
//void *trhead_function1(void *arg)
//void* arg = malloc(sizeof(int) + sizeof(double) + sizeof(char)); -> 변수하나에 3개 집어넣는 느낌.
//위와 같은 형태로 메모리 크기를 잡아준다.