/* A non-empty array A consists of non-negative integers.
* Given an array consists of N non-negative integers, returns
* minimum distance between two distant  elements of A
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void minDistance(int arr[], int size)
{
	printArray(arr, size);
	qsort(arr, size, sizeof(int), cmpfunc);
	int oldmindif = INT_MIN;
	int high;
	int i;
	for (i=0; i<size-1; i++)
	{
		int diff = abs(arr[i] - arr[i+1]);
		if (oldmindif > diff)
			oldmindif = diff;
	}
	printf("Minimum difference: %d\n", oldmindif); 	
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
	int array[] = {8,24,3,20,1,17};
	int size = sizeof(array)/sizeof(array[0]);
	minDistance(array, size);
	return 1;
}
