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

int main()
{
	char array[] = "This is for testing";
	//int array[] = {1, 3, 50, 10, 9, 7, 6};
	//int array[] = {10, 20, 30, 40, 50};
	//int array[] = {120, 100, 80, 20, 0};
	int tarray[256] = {0};

	int size = sizeof(array)/sizeof(array[0]);

	for(int i = 0; i < size; i++)
	{
		//printArray(tarray, 256);
		if (tarray[*(array + i)] != 1) 
		{
			tarray[*(array + i)] = 1;
			printf("%c", array[i]);
		}
	}
	printf("\n");
}
