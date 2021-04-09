#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dslib.h"

int main () {
  printf("Queue ------------------\n");
  Queue *Q = createQueue(3);

  printf(">>> ENQUEUE:\n");
  enqueue(1, Q);
  enqueue(5, Q);
  enqueue(7, Q);

  printf(">>> DISPLAY:\n");
  displayQueue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", getQueueSize(Q));

  printf(">>> DEQUEUE:\n");
  dequeue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", getQueueSize(Q));

  printf(">>> DISPLAY:\n");
  displayQueue(Q);

  printf(">>> DEQUEUE:\n");
  dequeue(Q);

  printf(">>> SIZE:\n");
  printf("%i\n", getQueueSize(Q));

  printf(">>> DISPLAY:\n");
  displayQueue(Q);

  deleteQueue(Q);

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Stack ------------------\n");
  Stack *S = createStack(3);

  printf(">>> PUSH:\n");
  stackPush(1, S);
  stackPush(2, S);
  stackPush(3, S);

  printf(">>> DISPLAY:\n");
  displayStack(S);

  printf(">>> SIZE:\n");
  printf("%i\n", getStackSize(S));

  printf(">>> POP:\n");
  stackPop(S);

  printf(">>> DISPLAY:\n");
  displayStack(S);

  printf(">>> SIZE:\n");
  printf("%i\n", getStackSize(S));
  
  deleteStack(S);
  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
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
  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Hufftree ------------------\n");

  printf(">>> DISPLAY + CREATE:\n");
  Hufftree H1 = createHufftree("WORD");
  displayHufftree(H1);
  putchar('\n');

  printf(">>> DISPLAY LEAVES + CREATE:\n");
  Hufftree H2 = createHufftree("DRIVE");
  displayLeaves(H2);
  putchar('\n');

  printf(">>> COMPRESS + CREATE:\n");
  char *string = "TEST";
  Hufftree H3 = createHufftree(string);
  compressString(string, H3);

  putchar('\n');

  printf(">>> DECOMPRESS + CREATE:\n");
  Hufftree H4 = createHufftree(string);
  decompressString("010110", H4);
  putchar('\n');

  deleteHufftree(H1);
  deleteHufftree(H2);
  deleteHufftree(H3);
  deleteHufftree(H4);
  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Linked List ------------------\n");
  List listA = \
  createNodeList(3, \
  createNodeList(1, \
  createNodeList(5, NULL)));

  printf(">>> SIZE LIST A\n");
  printf("%i\n", getListSize(listA));

  printf(">>> DISPLAY LIST A\n");
  displayList(listA);

  putchar('\n');

  printf(">>> REVERSE DISPLAY LIST A\n");
  displayReverseList(listA);

  putchar('\n');

  printf(">>> EMPTY LIST A\n");
  printf("%i\n", listIsEmpty(listA));

  printf(">>> HEAD LIST A\n");
  printf("%i\n", getListHead(listA));


  List listB = \
  createNodeList(2, \
  createNodeList(6, \
  createNodeList(5, \
  createNodeList(8, NULL))));

  //deleteList(&A);
  //deleteList(&B);

  List listC = *concatList(&listA, &listB);
  printf(">>> DISPLAY LIST C\n");
  displayList(listC);

  putchar('\n');
  printf(">>> EXIST\n");
  printf("%i\n", listItemExists(10, listC));

  List listD = cloneList(listC);

  deleteList(&listC);

  printf(">>> DISPLAY CLONE\n");
  displayList(listD);
  deleteList(&listD);

  putchar('\n');

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Map ------------------\n");
  Map MapA = createMap(145, "Test Drive", NULL);

  printf(">>> DISPLAY MAP A\n");
  displayMap(MapA);

  printf(">>> INSERT MAP A\n");
  insertMap(122, "Test 2", &MapA);
  insertMap(4, "Test 3", &MapA);
  insertMap(3, "Test 4", &MapA);
  insertMap(99, "Test 5", &MapA);

  removeMap(4, &MapA);

  printf(">>> FIND KEY\n");
  if (mapKeyExists(3, MapA)) {
    printf("Key found!\n");
  } else {
    printf("Key not found!\n");
  }

  deleteMap(&MapA);


  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Set ------------------\n");

  Set *SetA = createEmptySet(5);

  printf(">>> INSERT SET A\n");
  insertItemSet(SetA, 1);
  insertItemSet(SetA, 2);
  insertItemSet(SetA, 3);
  insertItemSet(SetA, 0);
  insertItemSet(SetA, 5);

  printf(">>> DISPLAY SET A\n");
  displaySet(SetA);

  printf(">>> REMOVE SET A\n");
  removeItemSet(SetA, 0);

  printf(">>> DISPLAY SET A\n");
  displaySet(SetA);

  Set *SetB = createEmptySet(4);
  printf(">>> INSERT SET B\n");
  insertItemSet(SetB, 5);
  insertItemSet(SetB, 6);
  insertItemSet(SetB, 3);
  insertItemSet(SetB, 8);

  printf(">>> DISPLAY SET B\n");
  displaySet(SetB);

  Set *SetC = unionSet(SetA, SetB);

  printf(">>> DISPLAY SET C (union (SetA, SetB))\n");
  displaySet(SetC);

  Set *SetD = intersectionSet(SetA, SetB);
  printf(">>> DISPLAY SET D (intersection (SetA, SetB))\n");
  displaySet(SetD); 

  Set *SetE = differenceSet(SetA, SetB);

  printf(">>> DISPLAY SET E (difference (SetA, SetB))\n");
  displaySet(SetE);

  printf("Highest value: %i\n", highestSetValue(SetE));
  printf("Lowest value: %i\n", lowestSetValue(SetE));
  printf("Size: %i\n", setSize(SetE));
  printf("Empty: %i\n", setIsEmpty(SetE));

  deleteSet(SetA);
  deleteSet(SetB);
  deleteSet(SetC);
  deleteSet(SetD);
  deleteSet(SetE);

  return 0;
}