#include <stdio.h>
#include "vector.h"

int main() {
  Vector vector;
  vector_init(&vector);

  for (int i=200; i>= -50; i--){
    printf("Appending %d to the vector\r\n", i);
    vector_append(&vector, i);
  }

  vector_set(&vector, 4452, 21312984);

  printf("The value at 27 is %d\r\n", vector_get(&vector, 27));
  printf("The size of the vector is %d\r\n", vector.size);

  vector_free(&vector);
}
