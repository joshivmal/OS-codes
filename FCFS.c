// #include<stdio.h>

// ******************************************* with arrival time 0 for all processes*****************************************************

// int main()
// {
//     int n;
//     printf("Enter the total number of processes ");
//     scanf("%d",&n);

//     int BT[n] ;
//     int CT[n] ;
//     int sum = 0 ;
//     printf("Enter the bus time for\n");

//     for(int i = 0 ; i<n ; i++)
//     {
//         printf("P%d ",i+1) ;
//         scanf("%d",&BT[i]);
//         sum+=BT[i];
//         CT[i] = sum ;
//     }

//     printf("Process \t AT \t BT \t CT \t TAT \t WT \t RT\n") ;
//     int WTSum = 0;
//     sum = 0 ;
//     for(int i=0;i<n;i++)
//     {
//         int WT = CT[i]-BT[i];
//         WTSum+=WT;
//         sum+=CT[i] ;
//         printf("P%d      \t %d \t %d \t %d \t %d \t %d \t %d\n",i+1,0,BT[i],CT[i],CT[i],WT,WT);

//     }
//     float avgTat = sum/(float)n ;
//     float avgWT = WTSum/(float)n;
//     printf("TAT : %d\n",sum);
//     printf("WT : %d\n",WTSum);

//     printf("Average TAT : %f\n",avgTat);
//     printf("Average avgWT : %f\n",avgWT);

// }

// ***************************************************FCFS with  arrival time**************************************************

#include <stdio.h>

int main()
{

  int n;
  printf("Enter the total number of processes ");
  scanf("%d", &n);
  int arr[10][6];

  printf("Enter the arrival time for\n");

  for (int i = 0; i < n; i++)
  {
    printf("P%d ", i + 1);
    arr[i][0] = i + 1;
    scanf("%d", &arr[i][1]);
  }
  printf("Enter the burst time for\n");

  for (int i = 0; i < n; i++)
  {
    printf("P%d ", i + 1);
    scanf("%d", &arr[i][2]);
  }

  for (int i = 0; i < n; i++)           // sort according to arriving time
  {
    int index = i;
    for (int j = i + 1; j < n; j++)
      if (arr[index][1] > arr[j][1])    index = j;

    if (index != i)
    {
      // swap(arr[j][1],arr[j+1][1]) ;   // swap arriving time
      int temp = arr[index][1];
      arr[index][1] = arr[i][1];
      arr[i][1] = temp;

      // swap(arr[j][2],arr[j+1][2]) ;    // swap burst time
      temp = arr[index][2];
      arr[index][2] = arr[i][2];
      arr[i][2] = temp;

      // swap process
      temp = arr[index][0];
      arr[index][0] = arr[i][0];
      arr[i][0] = temp;
    }
  }

  float tatSum = 0 ;
  float wtSum = 0 ;
  int sum = arr[0][1]; // starting from arriving time
  for (int i = 0; i < n; i++)
  {
    if (sum < arr[i][1])
      sum = arr[i][1]; // for idealness
    sum += arr[i][2];
    arr[i][3] = sum;                   // for  Completion Time
    arr[i][4] = sum - arr[i][1];       // for tat = CT-AT
    arr[i][5] = arr[i][4] - arr[i][2]; // for Waiting Time = TAT-BT
    tatSum += arr[i][4] ;
    wtSum += arr[i][5] ;
  }

  printf("Process  AT \t BT \t CT \t TAT \t WT \n");
  for (int i = 0; i < n; i++)
  {
    printf("p%d \t %d \t %d \t %d \t %d \t %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5]);
  }
  printf("Average TAT -> %0.2f \n",tatSum/n) ;
  printf("Average WT -> %0.2f \n",wtSum/n) ;
}
