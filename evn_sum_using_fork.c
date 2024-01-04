#include<stdio.h>
#include<unistd.h>

int main()
{
    int l ;
    printf("Enter the length of elements ");
    scanf("%d",&l) ;
    int arr[l];
 
    for(int i=0 ; i<l ; i++)
    {
        scanf("%d",&arr[i]);
    }


    int Esum = 0, Osum=0  ;
        int n =fork();

    if(n>0)
    {
        for(int i=0 ; i<l ; i++)
        {
            if(arr[i]%2 == 0) Esum+=arr[i] ;
        }
        printf("Parent process\n");
        printf("Sum of even numbers %d \n",Esum);
    }
    else
    {
        for(int i=0 ; i<l ;i++)
        {
            if(arr[i] % 2 != 0) Osum+=arr[i] ;
        }
        printf("Child process\n");
        printf("Sum of odd numbers %d \n",Osum);
    }
    return 0 ;
}