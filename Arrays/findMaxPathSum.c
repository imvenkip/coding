#include <stdio.h>
#include <stdlib.h>

#define N 3

void findSum2(int arr[], int sum, int size);
void printArray(int arr[], int size);

void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<=size-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int maxPathSum(int arr[][N], int m, int n)
{
	int i, j;

	for (i = m-1; i >= 0; i--)
	{
		for (j = 0; j <=n; j++)
		{
			if (arr[i+1][j] > arr[i+1][j+1]) 
                		arr[i][j] += arr[i+1][j]; 
            		else
                		arr[i][j] += arr[i+1][j+1]; 
		}
	}
	return(arr[0][0]);
}


int main()
{
	int array[N][N] = { {1, 0, 0}, 
        	          {4, 8, 0}, 
                	  {1, 5, 3} }; 
   	printf("Max path sum: %d\n", maxPathSum(array, 2, 2)); 
	return 0;
}
