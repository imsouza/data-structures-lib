#include <stdio.h>
#include <stdlib.h>
#include "../ds-lib.h"

int main () {
  printf("Linked List ------------------\n");
  List A = list(3, list(1, list(5, NULL)));
  List B = list(2, list(6, list(5, list(8, NULL))));

  printf(">>> SIZE\n");
  printf("%i\n", listSize(A));

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
  List C = list(-1, cloneList(A));

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