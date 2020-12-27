#include <stdio.h>
#include <stdlib.h>
#include "../ds-lib.h"

int main () {
  printf("Linked List ------------------\n");
  List A = createList(3, createList(1, createList(5, NULL)));
  List B = createList(2, createList(6, createList(5, createList(8, NULL))));

  printf(">>> SIZE\n");
  printf("%i\n", getListSize(A));

  printf(">>> DISPLAY\n");
  displayList(A);

  putchar('\n');

  printf(">>> REVERSE DISPLAY\n");
  displayReverseList(A);

  putchar('\n');

  printf(">>> EMPTY\n");
  printf("%i\n", listIsEmpty(A));

  printf(">>> HEAD\n");
  printf("%i\n", getHead(A));

  printf(">>> CONCAT\n");
  concatList(&A, &B);

  printf(">>> HEAD\n");
  printf("%i\n", getHead(A));

  printf(">>> DISPLAY\n");
  displayList(A);

  putchar('\n');

  printf(">>> REVERSE DISPLAY\n");
  displayReverseList(A);

  putchar('\n');

  printf(">>> CLONE/INSERT\n");
  List C = createList(-1, cloneList(A));

  printf(">>> DISPLAY\n");
  displayList(C);

  putchar('\n');

  printf(">>> HEAD\n");
  printf("%i\n", getHead(C));

  printf(">>> FIND\n");
  printf("%i\n", itemExists(10, C));

  printf(">>> FIND\n");
  printf("%i\n", itemExists(5, C));

  deleteList(&A);

  return 0;
}