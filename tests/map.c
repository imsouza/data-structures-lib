#include <stdio.h>
#include <stdlib.h>
#include "../src/ds-lib.h"

int main () {
  printf("Map ------------------\n");
  Map M = createMap(145, "Test Drive", NULL);

  printf(">>> DISPLAY\n");
  displayMap(M);

  printf(">>> INSERT\n");
  insertMap(122, "Test 2", &M);
  insertMap(4, "Test 3", &M);
  insertMap(3, "Test 4", &M);
  insertMap(99, "Test 5", &M);

  printf(">>> DISPLAY\n");
  displayMap(M);

  printf(">>> REMOVE KEY\n");
  removeMap(4, &M);

  printf(">>> DISPLAY\n");
  displayMap(M);

  printf(">>> FIND KEY\n");
  if (keyExists(3, M)) {
    printf("Key found!\n");
  } else {
    printf("Key not found!\n");
  }

  deleteMap(&M);

  return 0;
}