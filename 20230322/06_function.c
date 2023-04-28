#include <stdio.h>


void printArray(int *array, int size){ //int pointer, 배열 size| int *array -> int array[]로 선언해도 상관 없다. 배열이름 = 주소 
    for(int i = 0; i < 9; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int ascending(int x, int y){
    return x > y;
}

int decending(int x, int y){
    return x < y;
} //내림차순, 올림차순 정렬을 도와주는 비교기

int Sort(int* array, int size, int (*cmp_func)(int, int)){ //함수 호인터가 없다면 ascending decending을 가리킬 수 없어서 함수 포인터가 필요.
    for(int i = 0; i < 9; i++){
        for(int j = 1 + i; j < 9; j ++){
            if(cmp_func(array[i], array[j])){
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    return 0;
}

int main(){
    int array[9] = {3, 7, 9, 5, 6, 1, 8, 2, 4};

//Selection Sort
    void (*func_p)(int *array, int size); //함수포인터 변수로 선언, 이러한 함수를 가리킬 수 있다.
    func_p = printArray;
    Sort(array, 9, ascending);
    func_p(array, 9);
    Sort(array, 9, decending);
    func_p(array, 9);

 
    //배열 출력
    // func_p = (array, 9);
    return 0;
}
//함수포인터: printArray이름 자체를 pointer로 생각. 함수포인터는 int double 포인터와 비슷함. 함수 위치를 담을 수 있는 변수를 선언.
//void (*pointArray)(int * array, int size); -> 함수 포인터로 선언.
//**함수 포인터 사용하는 이유:
//값을 비교하는 과정 중 값을 비교하는 부분을 array[i] > array[j], array[i] < array[j] 두가지 경우 생기고, 이 두 가지를 모두 포함하는 sort함수를 만들려 함.
//연산자(<, >)를 매개변수로 받을 수는 없으니 이 부분을 함수로 만든다. 이 비교자리에 함수를 통해 비교하게 만듦.
//이때 이 함수가 ascending이냐 decending이냐에 따라 비교 조건이 달라 져야 함.
//이를 매개변수로 받으려면 매개변수에 함수를 선언해야함. 이 때 매개변수로 함수를 받기 위해 함수를 변수로 선언해야 함.
//특정함수를 매개변수로 만드는 변수가 필요. 어찌보면 type.
//이 함수를 받기 위해 함수 포인터를 통해서 주소를 매개변수로 받을 수 있고, 이 주소를 call하면 함수를 call 한다.

//void printArray(int array[], int size)와 (int *array, int size)의 차이는???
//-> 없다. 그냥 똑같다.
// int add(int x, int y, int * result){ -> 결과값은 매개변수를 통해서 주는 경우가 많음. 이때 이 매개변수를 받으려면 포인터로 받아야 함.
//     *result =12314124;
//     return 1;
// }