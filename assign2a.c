#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void InsertionSort(int *arr, int n) {
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++){
                        if (arr[i] > arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
        printf("I am in Insertion Sort\n");
         for (int i = 0; i < 5; i++) {

                 printf("%d ", arr[i]);
        }
         printf("\n");
}

void BubbleSort(int *arr, int n) {
        for (int i = 0; i < n; i++) {
                for (int j = 1; j < n; j++){
                        if (arr[j-1] > arr[j]) {
                                int temp = arr[j-1];
                                arr[j-1] = arr[j];
                                arr[j] = temp;
                        }
                }

        }
        printf("I am in Bubble Sort\n");
         for (int i = 0; i < 5; i++) {
                printf("%d ", arr[i]);
        }
         printf("\n");
}

int main() {

        int arr[5] = {5, 4, 3, 1, 2};

        pid_t cpid;

        if (fork() == 0) {
                printf("I am in child Process\n");
                InsertionSort(arr, 5);
                exit(0);
        }
        else {
                cpid = wait(NULL);
                printf("I am in Parent Process\n");
                BubbleSort(arr, 5);
        }

        /*BubbleSort(arr, 5);
        for (int i = 0; i < 5; i++) {
                printf("%d ", arr[i]);
        }*/


        return 0;
}
