#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dslib.h"

int main () {
  printf("Queue ------------------\n");
  Queue *Q = queueCreate(3);

  printf(">>> ENQUEUE:\n");
  queueEnqueue(1, Q);
  queueEnqueue(5, Q);
  queueEnqueue(7, Q);

  printf(">>> DISPLAY:\n");
  queueDisplay(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));

  printf(">>> DEQUEUE:\n");
  queueDequeue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));

  printf(">>> DISPLAY:\n");
  queueDisplay(Q);

  printf(">>> DEQUEUE:\n");
  queueDequeue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));

  printf(">>> DISPLAY:\n");
  queueDisplay(Q);

  queueDestroy(Q);

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Stack ------------------\n");
  Stack *S = stackCreate(3);

  printf(">>> PUSH:\n");
  stackPush(1, S);
  stackPush(2, S);
  stackPush(3, S);

  printf(">>> DISPLAY:\n");
  stackDisplay(S);

  printf(">>> SIZE:\n");
  printf("%i\n", stackSize(S));

  printf(">>> POP:\n");
  stackPop(S);

  printf(">>> DISPLAY:\n");
  stackDisplay(S);

  printf(">>> SIZE:\n");
  printf("%i\n", stackSize(S));
  
  stackDestroy(S);

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/

  printf("Binary Search Tree ------------------\n");
  BSTree *root = NULL;
  BSTree *searched;
  BSTree *max;
  BSTree *min;

  printf(">>> INSERT:\n");
  binarySearchTreeInsertNode(9, &root);
  binarySearchTreeInsertNode(2, &root);
  binarySearchTreeInsertNode(3, &root);
  binarySearchTreeInsertNode(15, &root);
  binarySearchTreeInsertNode(4, &root);
  binarySearchTreeInsertNode(1, &root);
  binarySearchTreeInsertNode(3, &root);
  binarySearchTreeInsertNode(7, &root);
  binarySearchTreeInsertNode(8, &root);

  printf(">>> DISPLAYS:\n");
  binarySearchTreeDisplayPreOrder(root);
  printf("------------------\n");
  binarySearchTreeDisplayInOrder(root);
  printf("------------------\n");
  binarySearchTreeDisplayPostOrder(root);
  printf("------------------\n");

  printf(">>> SEARCH:\n");
  printf("%i\n", binarySearchTreeSearch(545, &root));

  printf(">>> SEARCH:\n");
  printf("%i\n", binarySearchTreeSearch(15, &root));

  printf(">>> ROOT:\n");
  printf("%i\n", binarySearchTreeRoot(root));

  printf(">>> FIND MAX\n");
  max = binarySearchTreeFindMax(root);
  printf("%i\n", binarySearchTreeNode(max));

  printf(">>> FIND MIN\n");
  min = binarySearchTreeFindMin(root);
  printf("%i\n", binarySearchTreeNode(min));

  printf(">>> EMPTY:\n");
  printf("%i\n", binarySearchTreeIsEmpty(root));

  binarySearchTreeDestroy(root);

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/

  printf("Hufftree ------------------\n");

  printf(">>> DISPLAY + CREATE:\n");
  Hufftree H1 = hufftreeCreate("WORD");
  hufftreeDisplay(H1);
  putchar('\n');

  printf(">>> DISPLAY LEAVES + CREATE:\n");
  Hufftree H2 = hufftreeCreate("DRIVE");
  hufftreeDisplayLeaves(H2);
  putchar('\n');

  printf(">>> COMPRESS + CREATE:\n");
  char *string = "TEST";
  Hufftree H3 = hufftreeCreate(string);
  hufftreeCompressString(string, H3);

  putchar('\n');

  printf(">>> DECOMPRESS + CREATE:\n");
  Hufftree H4 = hufftreeCreate(string);
  hufftreeDecompressString("010110", H4);
  putchar('\n');

  hufftreeDestroy(H1);
  hufftreeDestroy(H2);
  hufftreeDestroy(H3);
  hufftreeDestroy(H4);

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/

  printf("Linked List ------------------\n");
  List *listA = linkedListCreate();

  linkedListInsertItemEnd(1, listA);
  linkedListInsertItemEnd(2, listA);
  linkedListInsertItemEnd(3, listA);
  linkedListInsertItemEnd(4, listA);
  linkedListInsertItemEnd(5, listA);

  printf(">>> DISPLAY LIST\n");
  linkedListDisplay(listA);

  printf(">>> REMOVE ELEMENT\n");
  linkedListRemove(5, listA);

  printf(">>> DISPLAY LIST\n");
  linkedListDisplay(listA);

  printf(">>> SIZE LIST\n");
  printf("%i\n", linkedListSize(listA));

  printf(">>> EMPTY LIST\n");
  printf("%i\n", linkedListIsEmpty(listA));

  printf(">>> LIST HEAD\n");
  Node *head = linkedListHead(listA);
  printf("%i\n", linkedListNode(head));

  printf(">>> LIST TAIL\n");
  Node *tail = linkedListTail(listA);
  printf("%i\n", linkedListNode(tail));

  linkedListDestroy(listA);

  putchar('\n');

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Map ------------------\n");
  Map MapA = mapCreate(145, "Test Drive", NULL);

  printf(">>> DISPLAY MAP A\n");
  mapDisplay(MapA);

  printf(">>> INSERT MAP A\n");
  mapInsert(122, "Test 2", &MapA);
  mapInsert(4, "Test 3", &MapA);
  mapInsert(3, "Test 4", &MapA);
  mapInsert(99, "Test 5", &MapA);

  printf(">>> DISPLAY MAP A\n");
  mapDisplay(MapA);

  printf(">>> REMOVE MAP A\n");
  mapRemove(4, &MapA);

  printf(">>> DISPLAY MAP A\n");
  mapDisplay(MapA);

  printf(">>> FIND KEY\n");
  if (mapKeyExists(3, MapA)) {
    printf("Key found!\n");
  } else {
    printf("Key not found!\n");
  }

  mapDestroy(&MapA);

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/

  printf("Set ------------------\n");

  Set *SetA = setCreate(5);

  printf(">>> INSERT SET A\n");
  setInsert(0, SetA);
  setInsert(5, SetA);
  setInsert(6, SetA);
  setInsert(2, SetA);
  setInsert(1, SetA);

  printf(">>> DISPLAY SET A\n");
  setDisplay(SetA);

  printf(">>> REMOVE SET A\n");
  setRemove(1, SetA);

  printf(">>> DISPLAY SET A\n");
  setDisplay(SetA);

  Set *SetB = setCreate(4);
  printf(">>> INSERT SET B\n");
  setInsert(1, SetB);
  setInsert(2, SetB);
  setInsert(3, SetB);
  setInsert(4, SetB);

  printf(">>> DISPLAY SET B\n");
  setDisplay(SetB);

  Set *SetC = setUnion(SetA, SetB);

  printf(">>> DISPLAY SET C (union (SetA, SetB))\n");
  setDisplay(SetC);

  Set *SetD = setIntersection(SetA, SetB);
  printf(">>> DISPLAY SET D (intersection (SetA, SetB))\n");
  setDisplay(SetD); 

  Set *SetE = setDifference(SetA, SetB);

  printf(">>> DISPLAY SET E (difference (SetA, SetB))\n");
  setDisplay(SetE);

  printf("Highest value: %i\n", setHighestValue(SetE));
  printf("Lowest value: %i\n", setLowestValue(SetE));
  printf("Size: %i\n", setSize(SetE));
  printf("Empty: %i\n", setIsEmpty(SetE));

  setDestroy(SetA);
  setDestroy(SetB);
  setDestroy(SetC);
  setDestroy(SetD);
  setDestroy(SetE);

  return 0;
}