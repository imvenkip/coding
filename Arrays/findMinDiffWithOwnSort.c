/* A non-empty array A consists of non-negative integers.
* Given an array consists of N non-negative integers, returns
* minimum distance between two distant  elements of A
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int arr[], int size);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int index = start;

	for (int i=start; i <= end-1; i++)
	{
		if (arr[i] <= pivot) {
			swap(&arr[i], &arr[index]);
			index++;
		}
	}	
	swap(&arr[index], &arr[end]);
	return index;
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pIndex = partition(arr, low, high);
		quickSort(arr, low, pIndex-1);
		quickSort(arr, pIndex+1, high);
	}
}

void minDistance(int arr[], int size)
{
	//printArray(arr, size);
	int curmindif=INT_MAX;
	int diff = 0;
	int start = 0;
	int end = size-1;
	quickSort(arr, start, end);
	//printArray(arr, size);

	for (int i=0; i<size-1; i++)
	{
		diff = abs(arr[i] - arr[i+1]);
		if (curmindif > diff)
			curmindif = diff;
		printf("%d %d %d %d\n", arr[i], arr[i+1], diff, curmindif);
	}
	printf("Minimum difference: %d\n", curmindif); 	
} 

void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<=size-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	//int array[] = {8,24,3,20,1,17};
	int array[] = {35,8,24,3,20,1,17,25,19,34,32,36};
	int size = sizeof(array)/sizeof(array[0]);
	int low = 0;
	printArray(array, size);
	quickSort(array, low, size-1);
	printArray(array, size);
	minDistance(array, size);
	return 1;
}
