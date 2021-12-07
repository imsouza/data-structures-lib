#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../src/dslib.h"

int main () {
  printf("Queue ------------------\n");
  Queue *queue = queueCreate();

  queueEnqueue(1, queue);
  queueEnqueue(5, queue);
  queueEnqueue(7, queue);

  queueDisplay(queue);

  printf("%i\n", queueSize(queue));

  queueDequeue(queue);

  printf("%i\n", queueSize(queue));

  queueDisplay(queue);

  queueDequeue(queue);

  printf("%i\n", queueSize(queue));

  queueDisplay(queue);

  queueDestroy(queue);





  /***********************************************************/





  printf("\n\n");

  printf("Stack ------------------\n");
  Stack *stack = stackCreate();

  stackPush(1, stack);
  stackPush(2, stack);
  stackPush(3, stack);

  stackDisplay(stack);

  printf("%i\n", stackSize(stack));

  stackPop(stack);

  stackDisplay(stack);

  printf("%i\n", stackSize(stack));
  
  stackDestroy(stack);





  /***********************************************************/





  printf("\n\n");

  printf("Binary Search Tree ------------------\n");
  BSTree *bstree = binarySearchTreeCreate();
  
  bstree = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(5), bstree);

  bstree = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(3), bstree);

  bstree = binarySearchTreeInsertNode(
         binarySearchTreeCreateNode(7), bstree);

  bstree = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(2), bstree);

  bstree = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(4), bstree);

  bstree = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(6), bstree);
  
  bstree = binarySearchTreeInsertNode( \
         binarySearchTreeCreateNode(1), bstree);

  displayTreePreOrder(bstree);
  printf("------------------\n");
  displayTreeInOrder(bstree);
  printf("------------------\n");
  displayTreePostOrder(bstree);
  printf("------------------\n");
  displayTree(0, bstree);
  printf("------------------\n");

  bstree = binarySearchTreeRemoveNode(2, bstree);
  displayTreePreOrder(bstree);

  putchar('\n');

  printf("%i\n", binarySearchTreeHeight(bstree));

  BSTree *searched = binarySearchTreeSearch(3, bstree);

  if (searched) {
    printf("%i? %i\n", 3, binarySearchTreeItem(searched));
  } else {
    printf("Node not found!\n");
  }

  printf("%i\n", binarySearchTreeTotalNodes(bstree));
  printf("%i\n", binarySearchTreeTotalLeafs(bstree));

  BSTree *max = binarySearchTreeFindMax(bstree);
  printf("%i\n", binarySearchTreeItem(max));

  BSTree *min = binarySearchTreeFindMin(bstree);
  printf("%i\n", binarySearchTreeItem(min));

  printf("%i\n", binarySearchTreeIsEmpty(bstree));

  printf("%i\n", binarySearchTreeIsBalanced(bstree));

  printf("%i\n", binarySearchTreeItemExists(1, bstree));

  binarySearchTreeDestroy(bstree);





  /***********************************************************/





  printf("\n\n");

  printf("AVL Tree ------------------\n");

  AVLTree *avltree = AVLTreeCreate();

  for (int i = 10; i<= 200; i += 10) {
    avltree = AVLTreeInsertNode(AVLTreeCreateNode(i), avltree);
  }

  displayTree(0, avltree);

  printf("%i", AVLTreeHeight(avltree));

  for (int i = 10; i<= 200; i += 10) {
    avltree = AVLTreeRemoveNode(i, avltree);
  }

  AVLTreeDestroy(avltree);





  /***********************************************************/





  printf("\n\n");

  printf("Linked List ------------------\n");
  List *list = linkedListCreate();

  linkedListInsertItemEnd(1, list);
  linkedListInsertItemEnd(2, list);
  linkedListInsertItemEnd(3, list);
  linkedListInsertItemEnd(4, list);
  linkedListInsertItemEnd(5, list);

  linkedListDisplay(list);

  linkedListRemove(5, list);

  linkedListDisplay(list);

  printf("%i\n", linkedListSize(list));

  printf("%i\n", linkedListIsEmpty(list));

  List *head = linkedListHead(list);
  printf("%i\n", linkedListItem(head));

  List *tail = linkedListTail(list);
  printf("%i\n", linkedListItem(tail));

  linkedListDestroy(list);

  putchar('\n');





  /***********************************************************/





  printf("\n\n");

  printf("Set ------------------\n");

  Set *set_A = setCreate(5);

  setInsert(0, set_A);
  setInsert(5, set_A);
  setInsert(6, set_A);
  setInsert(2, set_A);
  setInsert(-1, set_A);

  setDisplay(set_A);

  setRemove(0, set_A);

  setDisplay(set_A);

  Set *set_B = setCreate(6);
  setInsert(3, set_B);
  setInsert(2, set_B);
  setInsert(3, set_B);
  setInsert(4, set_B);
  setInsert(5, set_B);
  setInsert(-1, set_B);

  setDisplay(set_B);

  Set *set_C = setUnion(set_A, set_B);

  setDisplay(set_C);

  Set *set_D = setIntersection(set_A, set_B);
  setDisplay(set_D); 

  Set *set_E = setDifference(set_A, set_B);

  setDisplay(set_E);

  printf("%i\n", setHighestValue(set_E));
  printf("%i\n", setLowestValue(set_E));
  printf("%i\n", setSize(set_E));
  printf("%i\n", setIsEmpty(set_E));

  setDestroy(set_A);
  setDestroy(set_B);
  setDestroy(set_C);
  setDestroy(set_D);
  setDestroy(set_E);





  /***********************************************************/





  printf("\n\n");

  printf("Priority Queue ------------------\n");

  PrioQ *prioq = priorityQueueCreate();

  priorityQueueInsert(0, prioq);
  priorityQueueInsert(5, prioq);
  priorityQueueInsert(1, prioq);
  priorityQueueInsert(3, prioq);
  priorityQueueInsert(6, prioq);
  priorityQueueInsert(2, prioq);

  printf("%i\n", priorityQueueFirst(prioq));

  priorityQueueRemoveHighestPrio(prioq);

  priorityQueueRemoveHighestPrio(prioq);

  printf("%i\n", priorityQueueFirst(prioq));

  priorityQueueDestroy(prioq);





  /***********************************************************/



  

  printf("\n\n");

  printf("Graph ------------------\n");
  
  Graph *graph = graphCreate (5, 5, 0);

  graphInsertEdge(0, 1, 0, true, graph);
  graphInsertEdge(1, 3, 0, true, graph);
  graphInsertEdge(1, 2, 0, true, graph);
  graphInsertEdge(2, 4, 0, true, graph);
  graphInsertEdge(3, 0, 0, true, graph);
  graphInsertEdge(3, 4, 0, true, graph);
  graphInsertEdge(4, 1, 0, true, graph);

  graphDisplay(false, graph);

  graphRemoveEdge(4, 1, 0, true, graph);

  graphDisplay(false, graph);

  graphDepthFirstSearch(0, graph);
  graphDisplay(true, graph);

  graphBreadthFirstSearch(2, graph);
  graphDisplay(true, graph);

  graphDestroy(graph);





  /***********************************************************/





  printf("\n\n");

  printf("Red-Black Tree ------------------\n");

  RBTree *rbtree = redBlackTreeCreate();

  
  rbtree = redBlackTreeInsertNode( \
           redBlackTreeCreateNode(5), rbtree);

  rbtree = redBlackTreeInsertNode( \
           redBlackTreeCreateNode(3), rbtree);

  rbtree = redBlackTreeInsertNode( \
           redBlackTreeCreateNode(4), rbtree);

  rbtree = redBlackTreeInsertNode( \
           redBlackTreeCreateNode(2), rbtree);

  displayTree(0, rbtree); 
  redBlackTreeDestroy(rbtree);
  return 0;         
}