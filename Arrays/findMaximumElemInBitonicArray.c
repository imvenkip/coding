#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);

void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<=size-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int findMaximumNumber(int A[], int n)
{
	int low = 0;
	int high = n-1;
	int mid;

	if ( low == high)
		return low;

	

	while (low < high)
	{
		if ((low + 1 == high) && (A[low] >= A[high]))
			return low;

		if ((low + 1 == high) && (A[low] < A[high]))
			return high;

		mid = (low + high)/2;

		if ((A[mid] > A[mid+1]) &&  (A[mid] > A[mid-1]))
			return mid;
		else if (A[mid] < A[mid+1])
			low = mid;
		else
			high = mid;
	}	

	return mid;
}



int main()
{
	int array[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	//int array[] = {1, 3, 50, 10, 9, 7, 6};
	//int array[] = {10, 20, 30, 40, 50};
	//int array[] = {120, 100, 80, 20, 0};
	int size = sizeof(array)/sizeof(array[0]);
	int result = findMaximumNumber(array, size);

	if (result >= 0)
		printf("Maximum number: %d\n", array[result]);
	else
		printf("Maximum number is not found \n");
	return 1;
}
