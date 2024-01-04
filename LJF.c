#include <stdio.h>

int main()
{
    int n;
    float  btSum = 0 ;
    printf("Enter the number of processes ");
    scanf("%d", &n);
    int arr[n][9];
    printf("Enter the Arriving Time for \n");
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = i + 1;
        printf("P%d ", i + 1);
        scanf("%d", &arr[i][1]);
        arr[i][8] = 0;
    }
    printf("Enter the Bus Time for \n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ", i + 1);
        scanf("%d", &arr[i][2]);
        arr[i][7] = 0 ;
        // for throughput
        btSum+=arr[i][2] ;
    }

    int currentValue = 0;
    int completed = 0;
    float wtSum = 0, tatSum = 0 ;

    while(completed!=n)
    {
        int minIdx = -1 ;
        for(int i=0 ; i<n ;i++)
        {
            if(arr[i][1] <= currentValue && arr[i][7] != 1)
            {
                if(minIdx == -1 || arr[i][2] > arr[minIdx][2])
                {
                    minIdx = i ;
                }
            }
        }
        if(minIdx == -1) currentValue++ ;
        else
        {
            arr[minIdx][6] = currentValue-arr[minIdx][1] ;   // for responsive time
            currentValue += arr[minIdx][2] ;
            arr[minIdx][7] = 1 ;               // using column 7 as visited array
            arr[minIdx][3] = currentValue ;  // for completion value 
            arr[minIdx][4] = currentValue-arr[minIdx][1] ; // for TAT = CT - AT
            arr[minIdx][5] = arr[minIdx][4]-arr[minIdx][2] ;    // WT = TAT - BT

         // for average TAT and WT 
           wtSum += arr[minIdx][5] ;
           tatSum += arr[minIdx][4] ;

        }

        if(arr[minIdx][7] == 1) completed++ ;
    }
    

    printf("\n*********************Answer*************************\n\n");

    printf("Process   AT \t BT \t CT \t TAT \t WT \t RT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d \t %d \t %d \t %d \t %d \t %d \t %d \n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5], arr[i][6]);
    }
    printf("Average Waiting Time -> %f\n ", wtSum / n);
    printf("Average Responsive Sum -> %f\n ", wtSum / n);
    printf("Average TAT -> %f\n ",tatSum/n) ;
    printf("Throughput -> %f\n",n/btSum);


    return 0;
}