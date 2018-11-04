#include "merge_sort.h"

int *__merge(int arr1[], int arr2[])
{
  size_t size = sizeof(arr1)/sizeof(arr1[0]);
  int *result = malloc(size*2*sizeof(int));

  int currentIndex = 0;
  while (currentIndex != size*2)
  {
    if (arr1[currentIndex] <= arr2[currentIndex])
    {
      result[currentIndex] = arr1[currentIndex];
    }
    else
    {
      result[currentIndex] = arr2[currentIndex];
    }

    currentIndex++;
  }

  free(arr1);
  free(arr2);

  return result;
}

void merge_sort(int arr[])
{
  size_t size = sizeof(arr)/sizeof(arr[0]);

  if (size == 1) return;

  int half = size/2;

  int *firstHalf = (int*) malloc(sizeof(int) * half);
  int *secondHalf = (int*) malloc(sizeof(int) * half);

  memcpy(firstHalf, arr, half);
  memcpy(secondHalf, arr+half, half);

  merge_sort(firstHalf);
  merge_sort(secondHalf);
  int *result = __merge(firstHalf, secondHalf);
  free(firstHalf);
  free(secondHalf);

  for (int i=0; i<size; i++)
  {
    arr[i] = result[i];
  }
  free(result);
}
