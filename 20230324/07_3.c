#include <stdio.h>
#include <stdlib.h>

// struct node{
//     int* node;
//     struct node next;
// }; //struct는 data type 몇개를 묶어서 한 번에 선언 가능.

struct A{
    int a;
    double b;
    char c;
};// 각 요소 접근시에는 .a, .b같은 형식.

typedef struct {
    int *a;
    double b;
    char c;
}A; // 이렇게 선언해도 된다.


int main(){
    A *object = (A*)malloc(sizeof(A));
    printf("%ld\n", sizeof(A)); //int + double + char = 13인데 24 할당되어 있다. why?
    //-> int 4byte 할당. 그 다음  double할당 해야하나, 공간 X 따라서 8byte 8byte할당. 다음 char도 8byte 할다.ㅇ
    //만약 double, int char 순서로 하면. 8byte 할당, 두번째 공간 8byte로 만들고 4byte int넣고 char 1byte 넣어지므로 16byte 할당.
    object->a = (int*)malloc(sizeof(int));//*a로 정의시 *(object->a)로 사용해야 한다.
    *(object->a) = 1;
    object->b = 2.14;
    object->c = 'A';//얘가 포인터인데 접근을 이렇게 하는구나.
    // struct A object;
    // object.a = 1;
    // object.b = 2.14;
    // object.c = 'A';

    // printf("%d\n", object.a);
    // printf("%lf\n", object.b);
    // printf("%c\n", object.c);
    
}
//주소가 가리키는 메모리 영역을 해석할 줄 알아야 한다.