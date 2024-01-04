#include <stdio.h>

void displayFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int isPageFault(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 0; // Page hit, no fault
        }
    }
    return 1; // Page fault
}

void fifoPageReplacement(int pages[], int n, int frames[], int frameCount) {
    int pageFaults = 0;
    int front = 0; // Points to the front of the queue

    for (int i = 0; i < n; i++) {
        printf("Reference %d: Page %d - ", i + 1, pages[i]);
        
        if (isPageFault(frames, frameCount, pages[i])) {
            if (frames[front] != -1) {
                printf("Page %d is replaced by Page %d\n", frames[front], pages[i]);
            } else {
                printf("Page %d loaded\n", pages[i]);
            }

            frames[front] = pages[i];
            front = (front + 1) % frameCount;
            pageFaults++;

        } else {
            printf("Page %d is already in memory\n", pages[i]);
        }

        displayFrames(frames, frameCount);
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages) / sizeof(pages[0]);

    int maxFrames;
    printf("Enter the number of frames: ");
    scanf("%d", &maxFrames);

    int frames[maxFrames];
    for (int i = 0; i < maxFrames; i++) {
        frames[i] = -1; // Initialize frames with -1 to indicate an empty frame
    }

    printf("FIFO Page Replacement Policy\n");
    fifoPageReplacement(pages, n, frames, maxFrames);

    return 0;
}
