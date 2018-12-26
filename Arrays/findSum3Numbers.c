#include <stdio.h>
#include <stdlib.h>

void findSum2(int arr[], int sum, int size);
void printArray(int arr[], int size);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void findSum3(int arr[], int size, int sum)
{
	printArray(arr, size);
	qsort(arr, size, sizeof(int), cmpfunc);
	int low;
	int high;
	int i;

	for(i = 0; i < size-1; i++)
	{
		int calsum = sum - arr[i];
		for (low = i+1, high=size-1; low<high;)
		{
			int count = arr[low]+arr[high];
			if (count == calsum)
				printf("SUM %d is equl to %d + %d + %d \n", sum, arr[i], arr[low], arr[high]);

			if (count>sum)
				high--;
			else
				low++;
		}
	}
} 

void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<=size-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main(int argc, char **argv)
{
	printf("Arg count: %d\n", argc);
	int array[] = {1,3,2,5,7,8,10,3,6,3,4,8,99,100,234,23,45,3,24,56,32,67,34,23};
	int givensum = atoi(argv[1]);
	int size = sizeof(array)/sizeof(array[0]);
	findSum3(array, size, givensum);
	return 1;
}
