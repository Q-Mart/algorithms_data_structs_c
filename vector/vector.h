#define VECTOR_INITIAL_CAPACTITY 100

typedef struct {
  int size;
  int capacity;
  int *data;
} Vector;

void vector_init(Vector *vector);

void vector_append(Vector *vector, int value);

int vector_get(Vector *vector, int index);

void vector_set(Vector *vector, int index, int value);

void vector_double_capacity_if_full(Vector *vector);

void vector_free(Vector *vector);
