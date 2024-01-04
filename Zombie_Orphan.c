#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
  
// **********************************Zombie****************************************************
// process in which parent waits and  process terminates in child
int main()
{
    int n = fork() ;
    if(n > 0)
    {
        sleep(30) ;
        printf("Parent\n") ;

    }
    else
    {
        exit(0) ;
    }
    return 0 ;
}
//***********************************Orphan**************************************************
//  parent process finishes execution while the child process is still running prints
// int main()
// {
//     int n = fork() ;
//     if(n > 0)
//     {
//         printf("Parent\n") ;
//     }
//     else
//     {
//         sleep(30) ;
//         printf("Child\n") ;
//     }
//     return 0 ;
// }