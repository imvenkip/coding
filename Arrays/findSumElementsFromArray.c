/* Find the equivalent of array elements of sum is equal to given input? */


#include <stdio.h>
#include <stdlib.h>

void findSum(int arr[], int sum, int size);
void printArray(int arr[], int size);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void findSum(int arr[], int size, int sum)
{
	int start = 0; 
	int low = 0;
	int count = 0;
	int flag = 0;
	printArray(arr, size);
	qsort(arr, size, sizeof(int), cmpfunc);
	printArray(arr, size);

	for (low =0; low < size; low++)
	{
		printf("low : %d\n", low);
		count = count + arr[low];
		printf("count : %d\n", count);
		
		if (count == sum)
			break;
		else if (count > sum) {
			count = count - arr[start];
			start = start + 1;
			if (count == sum)
				break;
		} else 
			continue;	
	}
	printf("Sum is equal: %d\n ", sum);
	printf("Inexes: %d %d \n", start, low);
	for (flag = start; flag <= low; flag++)
		printf("%d, ", arr[flag]);
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
	findSum(array, size, givensum);
	return 1;
}
