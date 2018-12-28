#include <stdio.h>
#include <stdlib.h>

void findSum2(int arr[], int sum, int size);
void printArray(int arr[], int size);

void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<=size-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int findRepeatedNumber(int M, int A[], int n)
{
	int *count = malloc((M+1) * sizeof(int));
	int i;
	int index = -1;
	for (i=0; i <= M; i++)
		count[i] = 0;

	int maxOccur = 1;
	for (i = 0; i < n; i++)
	{
		if (count[A[i]] > 0)
		{
			int tmp = count[A[i]];
			tmp++;
			count[A[i]] = tmp;
			
			if ( tmp > maxOccur )
			{
				maxOccur = tmp;
				index = i;
			}
		} else {
			count[A[i]] = 1;
		}
	}
	free(count);
	return A[index];
}



int main()
{
	int array[] = {3,2,1,3,2,1,3};
	int size = sizeof(array)/sizeof(array[0]);
	int num = 3;
	int result = findRepeatedNumber(num, array, size);
	printf("Repeated number: %d\n", result);
	return 1;
}
