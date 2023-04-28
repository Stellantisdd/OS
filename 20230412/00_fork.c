#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
//fork함수가 불린 시점부터 프로그램이 하나 더 생기는 것. 새로 만들어진 process에는 flag값이 0
//child process PID가 0이라는 뜻은 아니고 fork 함수가 뱉는 값이 0이면 child process, 0아니면 parent process
//fork함수 불린 시점에서 프로그램입 복사되고, 기존 process에는 0이 아닌 값이 들어가고, 복제된 프로그램에는 0 들어감.
int main() {
    pid_t pid; //int 값. PID라고 표현하기 위해 이렇게 넣어준다.
    int flag;
    char *message;
    int n;

    printf("fork program starting\n");
    flag = fork();

    switch(flag)
    {
        case -1: // ERROR -> -1이 들어가면 fork가 안된 것!
            perror("fork failed");
            exit(1);
        case 0: // fork가 0이면 child process child process는 요 프로세스만 실행.
            message = "This is in the child";
            n = 7;
            break;
        default: // pid가 0이 아닌 놈이 결국 부모 프로세스.
            message = "This is the parent";
            n = 3;
            break;
    }   
    for(; n>0 ; n--){
        puts(message); //printf와 비슷.
        sleep(1);
        //1초마다 메세지 나온다.    
        //부모3, 자식 7번 출력하고 종료되어야함. 부모 3초 실행되고 종료되어야 함.
        //부모 프로세스가 끝나서 다음 명령어를 받으려고 This is the child 출력
        //child process 끝나기전까지 부모 process기다리는 기능 필요.
    }

    if( flag != 0){ //if문 안에는 child 들어가지 X. 부모 process만 들어가서 실행 된다.
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);//child process가 값을 반환하고 끝날 때 까지 기다린다. child process 끝난걸 parent에게 알리는 역할.
        //return되기 전까지 waiting
        //stat_val: child procdss가 어떤 상태로 끝났는지 알려주는 것. child process끝난 상태만 알려주는 것이 stat_val.
        //*if child process 끝나면 wait 다음 문장 실행.

        printf("parent process PID: %d\n", getpid());//부모 프로세스 상태 알려주는 함수. 부모 프로세스 = 현재 프로세스 상태에 대한 것.

        printf("Child has finished: PID = %d\n", child_pid);
        if ( WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }
    
    return 2;
}
