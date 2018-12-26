/* A non-empty array A consists of non-negative integers.
* Given an array consists of N non-negative integers, returns
* minimum distance between two distant  elements of A
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int arr[], int size);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void minDistance(int arr[], int size)
{
	printArray(arr, size);
	int curmindif=INT_MAX;
	int diff = 0;
	qsort(arr, size, sizeof(int), cmpfunc);
	printArray(arr, size);

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
	minDistance(array, size);
	return 1;
}
