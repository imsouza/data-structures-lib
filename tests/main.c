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
  dequeue(Q);
  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));
  printf(">>> DISPLAY:\n");
  displayQueue(Q);
  deleteQueue(&Q);

  printf("\n===============================================\n\n");

  printf("BSTree ------------------\n");
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
  searched = search(&root, 1);
  printf("%i\n", getNode(searched));

  printf(">>> ROOT:\n");
  printf("%i\n", getRoot(root));

  printf(">>> FIND MAX\n");
  max = findMax(root);
  printf("%i\n", getNode(max));

  printf(">>> FIND MIN\n");
  min = findMin(root);
  printf("%i\n", getNode(min));

  printf(">>> EMPTY:\n");
  printf("%i\n", emptyTree(root));

  deleteTree(root);

  return 0;
}