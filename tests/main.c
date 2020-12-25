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
  insertNode(9, &root);
  insertNode(2, &root);
  insertNode(3, &root);
  insertNode(15, &root);
  insertNode(4, &root);
  insertNode(1, &root);
  insertNode(3, &root);
  insertNode(7, &root);
  insertNode(8, &root);

  printf(">>> DISPLAYS:\n");
  displayPreOrder(root);
  printf("------------------\n");
  displayInOrder(root);
  printf("------------------\n");
  displayPostOrder(root);
  printf("------------------\n");

  printf(">>> SEARCH:\n");
  printf("%i\n", search(545, &root));

  printf(">>> SEARCH:\n");
  printf("%i\n", search(15, &root));

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
  printf("%i\n", itemExists(10, C));

  printf(">>> FIND\n");
  printf("%i\n", itemExists(5, C));

  deleteList(&A);

  printf("\n===============================================\n\n");

  printf("Map ------------------\n");
  Map M = nodeMap(145, "Test Drive", NULL);

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