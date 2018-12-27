/* Merge Overlapping intervals.
* let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. 
* The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. 
* Similarly {5, 7} and {6, 8} should be merged and become {5, 8}
* O/P: {(1,4}, {5,8});
*/

#include <stdio.h>
#include <stdlib.h>

struct interval
{
	int start;
	int end;
};

void printArray(struct interval arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d %d\n", arr[i].start, arr[i].end);
}

int compateInterval(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}


void mergeOverlapIntervals(struct interval arr[], int size)
{
	qsort(arr, size, sizeof(struct interval), compateInterval);
	printf("After sorting\n");
	printArray(arr, size);
	
	struct interval temparray[size];
	int j;
	int cur_index = 0;
	for ( j = 0; j < size;)
	{

		if ((j != (size-1)) && (arr[j].end > arr[j+1].start))
		{
			temparray[cur_index].start = arr[j].start;
			temparray[cur_index].end = arr[j+1].end;
			j = j+2;
		} else {
			temparray[cur_index].start = arr[j].start;
			temparray[cur_index].end = arr[j].end;
			j++;
		}
		cur_index++;
	}
	printf("After Merge overlapping\n");
	for (int i = 0; i < cur_index; i++)
		printf("%d %d\n", temparray[i].start, temparray[i].end);
}


int main() 
{
	//struct interval array[] = {{1,3}, {5,7}, {2,4}, {6,8}, {9,11}, {10,13}};
	struct interval array[] = {{1,3}, {5,7}, {2,4}, {6,8}, {9,11}};
	int size = sizeof(array)/sizeof(array[0]);
	printf("Before sorting\n");
	printArray(array, size);
	mergeOverlapIntervals(array, size);
}
