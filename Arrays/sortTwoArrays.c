#include <stdio.h>
#include <stdlib.h>

void findSum2(int arr[], int sum, int size);
void printArray(int arr[], int size);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    return (gap / 2) + (gap % 2); 
} 

/* O((n+m)*log(n+m)) time with O(1) extra space */

void merge(int arr1[], int m, int arr2[], int n) 
{ 
    printArray(arr1, m);
    printArray(arr2, n);
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    { 
        // comparing elements in the first array. 
        for (i = 0; i + gap < m; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(&arr1[i], &arr1[i + gap]); 
  
        //comparing elements in both arrays. 
        for (j = gap > m ? gap-m : 0 ; i < m&&j < n; i++, j++) 
            if (arr1[i] > arr2[j]) 
                swap(&arr1[i], &arr2[j]); 
  
        if (j < n) 
        { 
            //comparing elements in the second array. 
            for (j = 0; j + gap <n ; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(&arr2[j], &arr2[j + gap]); 
        } 
    } 
    printArray(arr1, m);
    printArray(arr2, n);
} 

/* This solution have time complexity is O(mn) */
/*
void sort2Arrays(int arr1[], int size1, int arr2[], int size2)
{
	printArray(arr1, size1);
	printArray(arr2, size2);
	int i,j;

	for (i = 0; i < size1; i++) {
		for (j = size2-1; j >= 0; j--) {
			if(arr2[j] < arr1[i])
				swap(&arr2[j], &arr1[i]);		
		}
	}	
	printArray(arr1, size1);
	printArray(arr2, size2);
} 
*/

void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<=size-1; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int array1[] = {1,3,5,7,8,10};
	int array2[] = {2,4,6,9,11,12};
	int size1 = sizeof(array1)/sizeof(array1[0]);
	int size2 = sizeof(array2)/sizeof(array2[0]);
	merge(array1, size1, array2, size2);
	return 1;
}
