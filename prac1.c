#include<stdio.h>
void bubble_sort(int arr[], int n){
	int i, j, temp;
	for (i = (n - 1) ; i > 0 ; i--){
		for (j = 1 ; j < i ; j++){
			if (arr[j-1] > arr[j]){
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

int binary_search(int arr[],int n, int x){
	int r, p;
	for (int l = 0, r = n - 1; l <=r ;){
		p = (l + r) / 2;
		if (arr[p] > x){
			r = p - 1;
		} else if (arr[p] < x){
			l = p + 1;
		} else {
			return p;
		}
		
	}
	return -1;
}

#define SIZE(x) (sizeof(x) / sizeof((x)[0]))
int main()
{
	printf("Bubble sort: \n");
	int arr[] = {3,6,1,3,7,8};
	int i;
	int n = SIZE(arr) - 1;
	for (i = 0 ; i < n ; i++){
		printf(' %d ', arr[i]);
	}
	printf(' \n ');
	bubble_sort(arr,n);
	printf("Sorting.. \n");
	for (i = 0 ; i < n ; i++){
		printf(' %d ', arr[i]);
	}
	return 0;
}


