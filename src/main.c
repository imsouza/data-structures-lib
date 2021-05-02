#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dslib.h"

int main () {
  printf("Queue ------------------\n");
  Queue *Q = queueCreate(3);

  queueEnqueue(1, Q);
  queueEnqueue(5, Q);
  queueEnqueue(7, Q);

  queueDisplay(Q);

  printf("%i\n", queueSize(Q));

  queueDequeue(Q);

  printf("%i\n", queueSize(Q));

  queueDisplay(Q);

  queueDequeue(Q);

  printf("%i\n", queueSize(Q));

  queueDisplay(Q);

  queueDestroy(Q);

  /***********************************************************/

  printf("\n\n");

  printf("Stack ------------------\n");
  Stack *S = stackCreate(3);

  stackPush(1, S);
  stackPush(2, S);
  stackPush(3, S);

  stackDisplay(S);

  printf("%i\n", stackSize(S));

  stackPop(S);

  stackDisplay(S);

  printf("%i\n", stackSize(S));
  
  stackDestroy(S);

  /***********************************************************/

  printf("\n\n");

  printf("Binary Search Tree ------------------\n");
  BSTree *root = NULL;
  root = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(1), root);

  root = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(3), root);

  root = binarySearchTreeInsertNode(
         binarySearchTreeCreateNode(4), root);

  root = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(2), root);

  root = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(3), root);

  root = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(8), root);

  binarySearchTreeDisplayPreOrder(root);
  printf("------------------\n");
  binarySearchTreeDisplayInOrder(root);
  printf("------------------\n");
  binarySearchTreeDisplayPostOrder(root);
  printf("------------------\n");
  binarySearchTreeDisplayTree(0, root);
  printf("------------------\n");

  root = binarySearchTreeRemoveNode(2, root);
  binarySearchTreeDisplayPreOrder(root);

  putchar('\n');

  printf("%i\n", binarySearchTreeHeight(root));

  BSTree *searched = binarySearchTreeSearch(3, root);

  if (searched) {
    printf("%i? %i\n", 3, binarySearchTreeGetItem(searched));
  } else {
    printf("Node not found!\n");
  }

  printf("%i\n", binarySearchTreeTotalNodes(root));
  printf("%i\n", binarySearchTreeTotalLeafs(root));

  BSTree *max = binarySearchTreeFindMax(root);
  printf("%i\n", binarySearchTreeGetItem(max));

  BSTree *min = binarySearchTreeFindMin(root);
  printf("%i\n", binarySearchTreeGetItem(min));

  printf("%i\n", binarySearchTreeIsEmpty(root));

  printf("%i\n", binarySearchTreeIsBalanced(root));

  printf("%i\n", binarySearchTreeItemExists(1, root));

  binarySearchTreeDestroy(root);

  /***********************************************************/

  printf("\n\n");

  printf("Hufftree ------------------\n");

  Hufftree H1 = hufftreeCreate("WORD");
  hufftreeDisplay(H1);
  putchar('\n');

  Hufftree H2 = hufftreeCreate("DRIVE");
  hufftreeDisplayLeaves(H2);
  putchar('\n');

  char *string = "TEST";
  Hufftree H3 = hufftreeCreate(string);
  hufftreeCompressString(string, H3);

  putchar('\n');

  Hufftree H4 = hufftreeCreate(string);
  hufftreeDecompressString("010110", H4);
  putchar('\n');

  hufftreeDestroy(H1);
  hufftreeDestroy(H2);
  hufftreeDestroy(H3);
  hufftreeDestroy(H4);

  /***********************************************************/

  printf("\n\n");

  printf("Linked List ------------------\n");
  List *listA = linkedListCreate();

  linkedListInsertItemEnd(1, listA);
  linkedListInsertItemEnd(2, listA);
  linkedListInsertItemEnd(3, listA);
  linkedListInsertItemEnd(4, listA);
  linkedListInsertItemEnd(5, listA);

  linkedListDisplay(listA);

  linkedListRemove(5, listA);

  linkedListDisplay(listA);

  printf("%i\n", linkedListSize(listA));

  printf("%i\n", linkedListIsEmpty(listA));

  Node *head = linkedListHead(listA);
  printf("%i\n", linkedListNode(head));

  Node *tail = linkedListTail(listA);
  printf("%i\n", linkedListNode(tail));

  linkedListDestroy(listA);

  putchar('\n');

  /***********************************************************/

  printf("\n\n");

  printf("Map ------------------\n");
  Map MapA = mapCreate(145, "Test Drive", NULL);

  mapDisplay(MapA);

  mapInsert(122, "Test 2", &MapA);
  mapInsert(4, "Test 3", &MapA);
  mapInsert(3, "Test 4", &MapA);
  mapInsert(99, "Test 5", &MapA);

  mapDisplay(MapA);

  mapRemove(4, &MapA);

  mapDisplay(MapA);

  if (mapKeyExists(3, MapA)) {
    printf("Key found!\n");
  } else {
    printf("Key not found!\n");
  }

  mapDestroy(&MapA);

  /***********************************************************/

  printf("\n\n");

  printf("Set ------------------\n");

  Set *SetA = setCreate(5);

  setInsert(0, SetA);
  setInsert(5, SetA);
  setInsert(6, SetA);
  setInsert(2, SetA);
  setInsert(1, SetA);

  setDisplay(SetA);

  setRemove(1, SetA);

  setDisplay(SetA);

  Set *SetB = setCreate(4);
  setInsert(1, SetB);
  setInsert(2, SetB);
  setInsert(3, SetB);
  setInsert(4, SetB);

  setDisplay(SetB);

  Set *SetC = setUnion(SetA, SetB);

  setDisplay(SetC);

  Set *SetD = setIntersection(SetA, SetB);
  setDisplay(SetD); 

  Set *SetE = setDifference(SetA, SetB);

  setDisplay(SetE);

  printf("%i\n", setHighestValue(SetE));
  printf("%i\n", setLowestValue(SetE));
  printf("%i\n", setSize(SetE));
  printf("%i\n", setIsEmpty(SetE));

  setDestroy(SetA);
  setDestroy(SetB);
  setDestroy(SetC);
  setDestroy(SetD);
  setDestroy(SetE);

  /***********************************************************/

  printf("\n\n");

  printf("Priority Queue ------------------\n");

  PrioQ *queue = priorityQueueCreate();

  priorityQueueInsert(0, queue);
  priorityQueueInsert(5, queue);
  priorityQueueInsert(1, queue);
  priorityQueueInsert(3, queue);
  priorityQueueInsert(6, queue);
  priorityQueueInsert(2, queue);

  printf("%i\n", priorityQueueFirst(queue));

  priorityQueueRemoveHighestPrio(queue);

  priorityQueueRemoveHighestPrio(queue);

  printf("%i\n", priorityQueueFirst(queue));

  priorityQueueDestroy(queue);

  return 0;
}