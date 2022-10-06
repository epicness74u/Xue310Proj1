#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "MS.h"

// l = left | m = middle | r = right
void merge(int arr[], int l, int m, int r, int flag, int printArr, int& ct)
{
  int sizeArr1 = m - l + 1;//<-- One
  int sizeArr2 = r - m;
  
  int *leftArr = new int[sizeArr1];
  int *rightArr = new int[sizeArr2];

  for (int i=0; i < sizeArr1; i++)
    {
      leftArr[i] = arr[l + i];
    }
  for (int j =0; j < sizeArr2; j++)
    {
      rightArr[j] = arr[m + 1 + j];
    }

  int indexArr1 = 0;
  int indexArr2 = 0;
  int indexMergeArr = l;

  while(indexArr1 < sizeArr1 && indexArr2 < sizeArr2)
    {
      ct++;
      if(flag == 1)
	{
	  printf("EWC: %d <= %d?\n", leftArr[indexArr1], rightArr[indexArr2]);
	}
      if(leftArr[indexArr1] <= rightArr[indexArr2])
	{
	  /* if(flag == 1)
	    {
	      printf("EWC: %d <= %d\n", leftArr[indexArr1], rightArr[indexArr2]);
	      }*/
	  arr[indexMergeArr] = leftArr[indexArr1];
	  if(printArr == 1)
	    {
	      printf("A[%d:%d]:", l, r);
	      for(int z = l; z < r+1; z++)
		{
		  printf(" %d", arr[z]);
		}
	      printf("\n");
	    }
	  indexArr1++;
	}
      else 
	{
	  arr[indexMergeArr] = rightArr[indexArr2];
	  if(printArr == 1)
	    {
	      printf("A[%d:%d]:", l, r);
	      for(int z = l; z < r+1; z++)
		{
		  printf(" %d", arr[z]);
		}
	      printf("\n");
	    }
	  indexArr2++;
	}
      indexMergeArr++;
    }
  while(indexArr1 < sizeArr1)
    {
      arr[indexMergeArr] = leftArr[indexArr1];
      if (printArr == 1)
	{
	  printf("A[%d:%d]:", l ,r);
	  for(int z = l; z < r+1; z++)
	    {
	      printf(" %d", arr[z]);
	    }
	  printf("\n");
	}
      indexArr1++;
      indexMergeArr++;
    }
  while(indexArr2 < sizeArr2)
    {
      arr[indexMergeArr] = rightArr[indexArr2];
      if(printArr==1)
	{
	  printf("A[%d:%d]:", l, r);
	  for(int z = l; z < r+1; z++)
	    {
	      printf(" %d", arr[z]);
	    }
	  printf("\n");
	}
      indexArr2++;
      indexMergeArr++;
    }
  delete[] leftArr;
  delete[] rightArr;
}

void MergeSortimpl(int arr[], int start, int end, int flag, int printArr, int& ct)
{
  if (start >= end)
    {
      return;
    }
  int mid = start +(end - start) /2;
  MergeSortimpl(arr, start, mid, flag, printArr, ct);
  MergeSortimpl(arr, mid+1, end, flag, printArr, ct);
  merge(arr, start, mid, end, flag, printArr, ct);
}
int MergeSort(int arr[], int start, int end, int flag, int printArr)
{
  int ct = 0;
  MergeSortimpl(arr, start, end, flag, printArr, ct);
  return ct;
}

    
