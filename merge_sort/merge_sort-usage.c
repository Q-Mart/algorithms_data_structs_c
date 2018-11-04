#include <stdio.h>
#include "merge_sort.h"

void prettyPrint(int arr[])
{
  printf("The array contains:\r\n");
  for (int i=0; i<10; i++)
  {
    printf("\t%d\r\n", arr[i]);
  }
}

int main()
{
  int numbers[10];

  for (int i=0; i<10; i++)
  {
    numbers[i] = 10-i;
  }

  prettyPrint(numbers);

  merge_sort(numbers);

  prettyPrint(numbers);

  return 0;
}
