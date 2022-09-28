#include <stdio.h>

void BubbleSort(int *arr, int n){
	for (int i = 0; i < n;i++){
		for (int j = 1; j < n-i; j++){
			if (arr[j-1] > arr[j]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

int main() {
	int burst[] = {6, 7, 3, 8};
	BubbleSort(burst, 4);
	int n = 4;
	int st = 0;
	int avgwt = 0;
	int wt[4];
	int tat = 0;
	for (int i = 0; i < n; i++){
		wt[i] = st;
		st += burst[i];
		avgwt += wt[i];
		tat += (wt[i] + burst[i]);
	}
	for (int i = 0; i < n; i++){
		printf("%d ", wt[i]);
	}
	printf("\n");
	avgwt = avgwt/4;
	tat = tat/4;
	printf("Average waiting time:- %d\n", avgwt);
	printf("Average Turnaround time:- %d\n", tat);
	bool j = true;
	if (j){
		printf("This boolean value is true");
	}
	
}
