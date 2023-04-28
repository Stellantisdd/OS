#include <stdio.h>
#include "myheader.h"
//07_4.c, myheader.h, sum.c 3개 파일  필요. 열어놓는다.
int main(){
    int a = 1;
    int b = 2;

    printf("%d\n", sum(a, b));

    return 0;
}