#include <stdlib.h>
#include <stdio.h>

int main(){
  // Allocate the pointers x and y
  int* x;
  int* y;

  x = malloc(sizeof(int));
  y = malloc(sizeof(int));

  *x = 42;
  *y = 13;

  printf("Pointer x: %p, y: %p\n", x, y);
  printf("Pointee x: %d, y: %d\n", *x, *y);

  y = x;
  *y = 13;

  printf("Pointer x: %p, y: %p\n", x, y);
  printf("Pointee x: %d, y: %d\n", *x, *y);

  return 0;
}
