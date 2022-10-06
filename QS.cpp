#include <stdlib.h>
#include <stdio.h>
#include <fstream>

void exchange(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int arr[], int lo, int hi, int flag, int printArr, int& ct)
{
  int temp = arr[hi];
  int i = (lo-1) ;

    for (int j = lo; j <= hi-1; j++)
      {
	
	if(flag == 1)
	  {
	    printf("EWC: %d <= %d?", arr[j], temp);
	    printf("\n");
	  }
	ct++;
	/*if(printArr == 1)
	  {
	    printf("A[%d:%d]: ",lo, hi);
	    for(int z =1; z <= hi; z++)
	      {
		printf("%d ", arr[z]);
	      }
	    printf("\n");
	    }*/
	if(arr[j] <= temp)
	  {
	    //ct++;
	    /* if(flag == 1)
	      {
		printf("EWC: %d <= %d?\n", arr[j], temp);
		}*/
	    i++;
	    //exchange(&arr[i], &arr[j]);
	    int temp2 = arr[i];
	    arr[i] = arr[j];
	    if(printArr == 1)
	      {
		printf("A[%d:%d]:", lo, hi);
		for(int z = lo; z <= hi; z++)
		  {
		    printf(" %d", arr[z]);
		  }
		printf("\n");
	      }
	    arr[j] = temp2;
	    if (printArr == 1)
	      {
		printf("A[%d:%d]:",lo,hi);
		for(int z = lo; z <= hi; z++)
		  {
		    printf(" %d", arr[z]);
		  }
		printf("\n");
	      }
	  }
      }
    // exchange(&arr[i+1], &arr[hi]);
    int temp3 = arr[i+1];
    arr[i+1] = arr[hi];
    if(printArr == 1)
      {
	printf("A[%d:%d]:",lo,hi); 
	for(int z = lo;z<=hi;z++)
	  {
	    printf(" %d", arr[z]);
	  }
	printf("\n");
      }
    arr[hi] = temp3;
    if(printArr == 1)
      {
	printf("A[%d:%d]:", lo, hi);
	for(int z = lo;z<= hi; z++)
	  {
	    printf(" %d", arr[z]);
	  }
	printf("\n");
      }
  return i+1;
}

void QuickSortimpl(int arr[], int lo, int hi, int flag, int printArr, int& ct)
{
  if (lo < hi)
    {
      int q = Partition(arr, lo, hi, flag, printArr, ct);
      QuickSortimpl(arr, lo, q-1, flag, printArr, ct);
      QuickSortimpl(arr, q+1, hi, flag, printArr, ct);
    }
}

int QuickSort(int arr[], int lo, int hi, int flag, int printArr)
{
  int ct = 0;
  QuickSortimpl(arr, lo, hi, flag, printArr, ct);
  return ct;
}

