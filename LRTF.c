#include <stdio.h>

int main()
{
    int n;
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
        arr[i][7] = arr[i][2];
    }

    // Sort according to arriving time (selection sort)

    for (int i = 0; i < n; i++)
    {
        int ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][1] > arr[j][1])
                ind = j;
        }
        if (ind != i)
        {
            // for arriving time
            int temp = arr[i][1];
            arr[i][1] = arr[ind][1];
            arr[ind][1] = temp;

            // for process
            temp = arr[i][0];
            arr[i][0] = arr[ind][0];
            arr[ind][0] = temp;

            // for burst time
            temp = arr[i][2];
            arr[i][2] = arr[ind][2];
            arr[ind][2] = temp;

            // for remaining time
            temp = arr[i][7];
            arr[i][7] = arr[ind][7];
            arr[ind][7] = temp;
        }
    }

    int currentValue = 0;
    int complete = 0;
    while (complete < n)
    {
        int minJobIndex = -1;
        // this loop is used for finding the index with shortest remaining time
        for (int i = 0; i < n; i++)
        {
            if (arr[i][1] <= currentValue && arr[i][7] > 0)
                if (minJobIndex == -1 || arr[i][7] > arr[minJobIndex][7])
                    minJobIndex = i;
        }
        if (minJobIndex == -1)
            currentValue++;

        else
        {
            int index = minJobIndex;
            arr[index][3] = currentValue + 1; // completion time
            arr[index][7]--;                  // remaining time


            if (!arr[index][8]) // for responsive time
            {
                arr[index][6] = currentValue - arr[index][1];
                arr[index][8] = 1;
            }

            arr[index][4] = arr[index][3] - arr[index][1]; // TAT = CT - AT
            arr[index][5] = arr[index][4] - arr[index][2]; // Waiting Time = TAT - BT

            currentValue++;

            if (arr[index][7] == 0)
                complete++;
        }
    }
    float WTSum = 0, RTSum = 0;
    for (int i = 0; i < n; i++)
    {
        WTSum += arr[i][5];
        RTSum += arr[i][6];
    }

    printf("\n*********************Answer*************************\n\n");

    printf("Process   AT \t BT \t CT \t TAT \t WT \t RT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d \t %d \t %d \t %d \t %d \t %d \t %d \n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5], arr[i][6]);
    }
    printf("Waiting Sum -> %f\n ", WTSum / n);
    printf("Responsive Sum -> %f ", RTSum / n);

    return 0;
}