#include <stdio.h>
// gcc '파일명'
//./a.out으로 실행
//gcc 02_condition.c -o test -> test로 이름지정해서 실행 가능해짐.
// ./test
int main()
{
int i, j;

for (j = 0; j < 6; j++){
    for(i = j; i < 6; i++){
        printf("*");
    }
    printf("\n");

}


}