#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "IS.h"
#include "QS.h"
#include "MS.h"

using namespace std;

int ident;
int printAR, printEWC;

int main(int argc, char *argv[])
{
  FILE *fp;
  int alg, flag, i, n, EWC_ct;
  int *arr;

  ident = 0; printAR = 0;
  /*printf("argc=%d\n",argc);
  for (int i=0; i <argc; i++)
    {
      printf("The str value of argv[%d] is %s\n", i, argv[i]);
      //printf("The int value of argc[%d] is %d\n\n", i, atoi(argv[i]));
      }*/
  //FILE *fp1, *fp2;
  int printRes, printArr, arrSize;
  //float x;
  //double y;
  
  if (argc < 3)
    {
      printf("Usage: ./PJ1 alg flag\n       alg should be in {InsertionSort, MergeSort, QuickSort}\n       flag should be in {0, 1}\n");
      exit(1);
    }

  if (strcmp(argv[1], "InsertionSort") == 0)
    {
      alg = 1;
    }
  else if (strcmp(argv[1], "MergeSort")== 0)
    {
      alg = 2;
    }
  else if (strcmp(argv[1], "QuickSort")== 0)
    {
      alg = 3;
    }
    else
    {
      printf("Usage: ./PJ1 alg flag\n       alg should be in {InsertionSort, MergeSort, QuickSort}\n       flag should be in {0, 1}\n");
      exit(1);
    }


  /*fp1 = fopen(argv[1], "r");
  if (fp1 == NULL)
    {
      fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
      exit(1);
    }
  fp2 = fopen(argv[2], "w");
  if (fp2 == NULL)
    {
      fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
      exit(1);
      }*/

  flag = atoi(argv[2]); //flag value
  if (flag !=0 && flag !=1)
    {
      printf("Usage: ./PJ1 alg flag\n       alg should be in {InsertionSort, MergeSort, QuickSort}\n       flag should be in {0, 1}\n");
      exit(1);
    }
  printEWC = flag;

  fp = fopen("INPUT.txt", "r");
  if (fp == NULL)
    {
      printf("Error: cannot open file INPUT.txt\n");
      exit(1);
    }
  int count = 0;
  //int temp = 0;
  int subArr[1000];
  while(fscanf(fp, "%d",&n) == 1)
    {
      count++;
      if (count == 1)
	{
	  printRes = n;
	  subArr[count] = printRes;
	}
      else if(count == 2)
	{
	  printArr = n;
	  subArr[count] = printArr;
	}
      else if(count == 3)
	{
	  arrSize = n;
	  subArr[count] = arrSize;
	  // arr =(int*)malloc((arrSize)*sizeof(int));
	}
      else 
	{
	  subArr[count] = n;
	}
      //int z = 1;
      // arr[z] = n;
      // z++;
    }
  // printf("%d %d %d", printRes,printArr,arrSize);

  arr = (int*)malloc((arrSize)*sizeof(int));
  
  int y = 1;
  for(int z=4; z <= arrSize+3; z++)
    {
      arr[y] = subArr[z];
      y++;
    } 
  
  /* while(fscanf(fp, "%d", &n) == 1)
    {
      i++;
      if(i > 3)
	{
	  printf("%d ", n);
	  arr[i] = n;
	}
	}*/
  //arr = (int *) malloc((n+1)*sizeof(int));
  
  if (arr == NULL)
    {
      fprintf(stderr,  "Error: cannot allocate memory\n");
      exit (1);
    }
  /*for (i=1; i<n; i++)
    {
      fscanf(fp, "%d", &arr[i]);
    }
  for (i=0; i<n-1; i++)
    {
      printf("%d ", arr[i]);
      printf("%d\n", arr[n-1]);
    }*/
  /*printf("\ntest 1\n");
  for (int j =1; j < 4; j++)
    {
      printf(" %d", subArr[j]);
    }
  printf("\ntest 2\n");
  for(int k = 1; k <= arrSize+1; k++)
    {
      printf(" %d", arr[k]);
    }
  printf("\ntest 3\n");
  */

  // alg = argv[1];

  switch(alg)
    {
    case 1: EWC_ct = InsertionSort(arr, 1, arrSize, flag, printArr);
      break;
      
    case 2: EWC_ct = MergeSort(arr, 1, arrSize, flag, printArr);
      break;
      
    case 3: EWC_ct = QuickSort(arr, 1, arrSize, flag, printArr);
      break;
    }
  /*  
  if(printArr)
    {
      printf("printArr = 1");
      }*/
  
  if(printRes)
    {
      printf("A[%d:%d] after sorting:", 1, arrSize);
      for(i=1; i <arrSize+1; i++)
	{
	  printf(" %d", arr[i]);
	}
      printf("\n");
    }
  if(printEWC == 1 || printEWC ==0)
    {
      printf("Number of EWCs: %d\n", EWC_ct);
    }
  
  free(arr);

  return EWC_ct;
}
  
