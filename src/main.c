#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dslib.h"

int main () {
  printf("Queue ------------------\n");
  Queue Q = createQueue(3);

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

  deleteQueue(&Q);

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Stack ------------------\n");
  Stack S = createStack(3);

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
  
  deleteStack(&S);
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
  List A = \
  createNodeList(3, \
  createNodeList(1, \
  createNodeList(5, NULL)));

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


  List B = \
  createNodeList(2, \
  createNodeList(6, \
  createNodeList(5, \
  createNodeList(8, NULL))));

  //deleteList(&A);
  //deleteList(&B);

  List C = *concatList(&A, &B);
  printf(">>> DISPLAY\n");
  displayList(C);

  putchar('\n');
  printf(">>> EXIST\n");
  printf("%i\n", itemExists(10, C));

  List D = cloneList(C);

  deleteList(&C);

  printf(">>> DISPLAY CLONE\n");
  displayList(D);
  deleteList(&D);

  putchar('\n');

  /***********************************************************/

  sleep(1); printf("\n\n");

  /***********************************************************/
  printf("Set ------------------\n");

  Set *s = createEmptySet(5);

  printf(">>> INSERT SET S\n");
  insertItemSet(s, 1);
  insertItemSet(s, 2);
  insertItemSet(s, 3);
  insertItemSet(s, 0);
  insertItemSet(s, 5);

  printf(">>> DISPLAY SET S\n");
  displaySet(s);

  printf(">>> REMOVE SET S\n");
  removeItemSet(s, 0);

  printf(">>> DISPLAY SET S\n");
  displaySet(s);

  Set *t = createEmptySet(4);
  printf(">>> INSERT SET T\n");
  insertItemSet(t, 5);
  insertItemSet(t, 6);
  insertItemSet(t, 3);
  insertItemSet(t, 8);

  printf(">>> DISPLAY SET T\n");
  displaySet(t);

  Set *u = unionSet(s, t);

  printf(">>> DISPLAY SET U (union (s, t))\n");
  displaySet(u);

  Set *i = intersectionSet(s, t);
  printf(">>> DISPLAY SET I (intersection (s, t))\n");
  displaySet(i); 

  Set *d = differenceSet(s, t);

  printf(">>> DISPLAY SET D (difference (d, s))\n");
  displaySet(d);

  printf("Highest value: %i\n", highestSetValue(d));
  printf("Lowest value: %i\n", lowestSetValue(d));
  printf("Size: %i\n", setSize(d));
  printf("Empty: %i\n", setIsEmpty(d));

  deleteSet(u);
  deleteSet(s);
  deleteSet(t);
  deleteSet(i);
  deleteSet(d);

  return 0;
}