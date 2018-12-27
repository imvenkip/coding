/* Find a missiong number from n numbers. n is also array size.
* Example :
* I/P    [1, 2, 4, ,6, 3, 7, 8]
* O/P    5
* O(n)
*/



#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);

void findmissingnumber(int arr[], int size)
{
	int sum = (size * (size+1))/2;
	printArray(arr, size);
	printf("SUM: %d\n", sum);
	for (int i=0; i<size-1; i++)
		sum = sum - arr[i];

	printf("Missiong number: %d\n", sum);
}


void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<size-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int array[] = {1,2,3,5,6,7,4,8,9,10,11,14,12,15};
	int size = (sizeof(array)/sizeof(array[0]))+1;
	findmissingnumber(array, size);
	return 1;
}
