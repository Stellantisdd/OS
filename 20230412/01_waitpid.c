#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int flag;
    int status;

    flag = fork();
    //p.process의 fork 값은 0아닌 값이 들어간다고 했는데, 이것이 c.process의 pid값.
    //즉, p.process의 fork값은 c.process의 pid값.

    if(flag == 0){
        printf("child process\n");
        sleep(10);
        return 2;
    }else{
        printf("Parent: wait child process %d\n", flag);
        waitpid(flag, &status, 0);//매개변수 3개. 1에는 내가 상태를 알고 싶은 pid값.(현재는 flag에 c.process의 pid)
        //flag에 해당하는 c.process가 끝날때 까지 기다리겠다. flag의 process가 끝났을 때 상태를 출력.(&status)
        //status라는 변수에 c.process의 pid값을 저장.
        if(WIFEXITED(status)){
            printf("child process exit with code %d\n", WEXITSTATUS(status));
        }else if(WIFSIGNALED(status)){
            printf("child process exit with code %d\n", WTERMSIG(status));
        //if signaled: child process가 어떤 signal에 대해서 종료되었을 때.
        //termsig: ifsignaled가 nonzero일 때 어떤 signal로 종료했는가.
        }
    return 0;
}
//status는 그냥 상태. c.process가 어떻게 끝났다는 상태이지 return값 자체를 의미하지는 X
//os로 return이 넘어가고 parent가 os에서 return을 받는다.
//fork나 wait쓰는 것을 system programming이라고 한다.
//WIFEXITED(status): status의 하위 8비트 데이터를 보고 결과값을 뱉어낸다. 쉽게 생각해서 status reg.