#include <stdio.h>
#include <stdlib.h>
#include "../ds-lib.h"

int main () {
  printf("Stack ------------------\n");
  Stack S = stack(3);

  printf(">>> PUSH:\n");
  stackPush(1, S);
  stackPush(2, S);
  stackPush(3, S);

  printf(">>> DISPLAY:\n");
  displayStack(S);

  printf(">>> SIZE:\n");
  printf("%i\n", stackSize(S));

  printf(">>> POP:\n");
  stackPop(S);

  printf(">>> DISPLAY:\n");
  displayStack(S);

  printf(">>> SIZE:\n");
  printf("%i\n", stackSize(S));
  
  deleteStack(&S);

  printf("\n===============================================\n\n");

  printf("Queue ------------------\n");
  Queue Q = queue(3);

  printf(">>> ENQUEUE:\n");
  enqueue(1, Q);
  enqueue(5, Q);
  enqueue(7, Q);

  printf(">>> DISPLAY:\n");
  displayQueue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));

  printf(">>> DEQUEUE:\n");
  dequeue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));

  printf(">>> DISPLAY:\n");
  displayQueue(Q);

  printf(">>> DEQUEUE:\n");
  dequeue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));

  printf(">>> DISPLAY:\n");
  displayQueue(Q);

  deleteQueue(&Q);

  printf("\n===============================================\n\n");

  printf("Binary Search Tree ------------------\n");
  BSTree *root = NULL;
  BSTree *searched;
  BSTree *max;
  BSTree *min;

  printf(">>> INSERT:\n");
  insert(&root, 9);
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 15);
  insert(&root, 4);
  insert(&root, 1);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 8);

  printf(">>> DISPLAYS:\n");
  displayPreOrder(root);
  printf("------------------\n");
  displayInOrder(root);
  printf("------------------\n");
  displayPostOrder(root);
  printf("------------------\n");

  printf(">>> SEARCH:\n");
  printf("%i\n", search(&root, 545));

  printf(">>> SEARCH:\n");
  printf("%i\n", search(&root, 15));

  printf(">>> ROOT:\n");
  printf("%i\n", getRoot(root));

  printf(">>> FIND MAX\n");
  max = findMax(root);
  printf("%i\n", getNode(max));

  printf(">>> FIND MIN\n");
  min = findMin(root);
  printf("%i\n", getNode(min));

  printf(">>> EMPTY:\n");
  printf("%i\n", treeIsEmpty(root));

  deleteTree(root);

  printf("\n===============================================\n\n");

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
  printf("%i\n", findItem(10, C));

  printf(">>> FIND\n");
  printf("%i\n", findItem(5, C));

  deleteList(&A);

  return 0;
}