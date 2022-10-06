#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>
#include "IS.h"

int InsertionSort(int arr[], int a, int b, int c, int printArr)
{
  int ct = 0;
  for (int i = a+1; i <= b; i++)
    {
      int temp = arr[i];
      int j = i-1;
      // printf("%d<= %d\n", arr[j], temp);
      if(arr[j] <= temp)
	{
	  ct++;
	  if(c==1)
	    {
	      printf("EWC: %d > %d?\n", arr[j],temp);
	    }
	}
      
      while (j > 0 && arr[j] > temp)
	{
	  ct++;
	  if(c==1)
	    {
	      printf("EWC: %d > %d?\n", arr[j], temp);
	    }
	  arr[j+1] = arr[j];
	  if(printArr == 1)
	    {
	      printf("A[%d:%d]:", a, b);
	      for(int z = 1; z <= b; z++)
		{
		  printf(" %d", arr[z]);
		}
	      printf("\n");
	    }
	  j = j-1;
	}
      
      arr[j+1] = temp;
      if(printArr == 1)
	{
	  printf("A[%d:%d]:",a ,b);
	  for(int z = 1; z <=b; z++)
	    {
	      printf(" %d", arr[z]);
	    }
	  printf("\n");
	}
    }
  return ct;
}
 
