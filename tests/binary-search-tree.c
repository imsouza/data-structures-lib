#include <stdio.h>
#include <stdlib.h>
#include "../src/dslib.h"

int main () {
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

  return 0;
}