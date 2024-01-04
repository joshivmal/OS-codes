#include<stdio.h>

int main()
{
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    int n = sizeof(pages)/sizeof(pages[0]) ;
    int f = 3 ;
    int frame[3] ;
    int temp[3] ;
    for(int i=0 ; i<3 ; i++)  frame[i] = -1 ;
    int page_fault = 0;
    int position;
    
    for(int i=0 ; i< n ; i++)
    {
        int a = 0 , b= 0 ;

        for(int j = 0 ; j< f ; j++)
        {

            if(pages[i] ==  frame[i])
            {
                a =1 ;
                b = 1; 
                break ;
            }
        }
        if ( a == 0)
            {
                for(int j =0 ; j<f ; j++)
                {
                    if(frame[j] == -1){
                        b = 1;
                        frame[j] = pages[i] ; 
                        page_fault++ ;
                        break ;
                    }
                }
            }
            if( b== 0)
            {
                for(int m=0 ; m<f ;m++)
                {
                    temp[m] = 0 ;
                }
            
                for(int  l= 1,j= i-1 ; l<=f-1 ;j--,l++)
                {
                    for(int m = 0; m < f ; m++)
                    {
                        if(frame[m] == pages[j]){
                            temp[m] = 1;
                        }
                    }
                }
                for(int k= 0 ; k<f ;k++ )
                {
                    if(temp[k] == 0)
                    {
                        position = k ;
                    }
                }
                frame[position] = pages[i] ;
                page_fault++ ;
            }
            for(int m = 0; m < f; m++)
            {
                printf("%d\t", frame[m]);
            }
            printf("\n");
        
    }

    return 0 ;
}