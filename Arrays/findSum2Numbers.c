#include <stdio.h>
#include <stdlib.h>

void findSum2(int arr[], int sum, int size);
void printArray(int arr[], int size);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void findSum2(int arr[], int size, int sum)
{
	printArray(arr, size);
	qsort(arr, size, sizeof(int), cmpfunc);
	int low;
	int high;

	for (low =0, high=size-1; low<high;)
	{
		int count = arr[low]+arr[high];
		if (count == sum)
			printf("SUM %d is equl to %d + %d\n", sum, arr[low], arr[high]);

		if (count>sum)
			high--;
		else
			low++;
	}
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
	int array[] = {1,3,2,5,7,8,10};
	int givensum = 11;
	int size = sizeof(array)/sizeof(array[0]);
	findSum2(array, size, givensum);
	return 1;
}
