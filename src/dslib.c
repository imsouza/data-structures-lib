/**********************************************************************************
 * MIT License                                                                    *
 *                                                                                *
 * Copyright (c) 2020 Mateus Almeida                                              *
 *                                                                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          *
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in all *
 * copies or substantial portions of the Software.                                *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
 * SOFTWARE.                                                                      *
 **********************************************************************************/

/**
 * @file dslib.c
 * @brief A library of data structures for academic purposes
 * @author Mateus Almeida
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "dslib.h"


struct stack {
  Node *head;
  int qty;
};


struct queue {
  Node *head;
  Node *tail;
  int qty;
};


struct bstree {
  long int item;
  struct bstree *left;
  struct bstree *right;
};


struct htree {
  struct htree *left;
  char chr;
  long int frq;
  struct htree *right;
};


struct list {
  Node *head;
  Node *tail;
  int qty;
};


struct map {
  long int key;
  char value[SIZE];
  struct map *next;
};


struct set {
  long int *values;
  long int size;
};


struct pvalue {
  long int prio;
};


struct prioq {
  long int first;
  long int last;
  int qty;
  struct pvalue pvalue_t[SIZE];
};


const char * const messages[] = {
    "[!] Stack overflow!\n",  // 0
    "[!] Stack underflow!\n", // 1
    "[!] Empty stack!\n",     // 2
    "[!] The queue is full!\n", // 3
    "[!] The queue is empty!\n",// 4
    "[!] The tree is empty!\n", // 5
    "[!] Node not found in the tree!\n", // 6 
    "[!] The list is empty!\n",          // 7
    "[!] Error allocating memory!\n",    // 8
    "[!] Element not found!\n",          // 9
    "[!] Key not found!\n",              // 10
};


Stack 
*stackCreate () {
  Stack *stack = malloc (sizeof(Stack));
  stack->head = NULL;
  stack->qty = 0;
  return stack;
}


long int 
stackIsEmpty (Stack *stack) {
  return stack->qty == 0;
}


void 
stackPush (long int item, Stack *stack) {
  Node *new = malloc (sizeof(Node));
  new->item = item;
  new->next = stack->head;
  stack->head = new;
  stack->qty++;
}


void 
stackPop (Stack *stack) {
  if (stackIsEmpty(stack)) {
    printf("%s", messages[1]);
    abort();
  } else {
    Node *temp = stack->head;
    stack->head = temp->next;
    stack->qty--;
    free(temp);
  }
}


long int
stackTop (Stack *stack) {
  if (stackIsEmpty(stack)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return stack->head->item;
  }
}


long int 
stackSize (Stack *stack) {
  return stack->qty;
}


void 
stackDisplay (Stack *stack) {
  if (stackIsEmpty(stack)) {
    printf("%s", messages[2]);
    abort();
  } else {
    Node *temp = stack->head;

    while (temp) {
      printf("%li ", temp->item);
      temp = temp->next;
    }

    putchar('\n');
  }
}


void 
stackDestroy (Stack *stack) {
  Node *aux = stack->head;

  while (aux) {
    Node *temp = aux->next;
    free(aux);
    aux = temp;
  }

  free(stack);
  stack = NULL;
}


Queue 
*queueCreate () {
  Queue *queue  = malloc (sizeof(Queue));
  queue->head = queue->tail = NULL;
  queue->qty = 0;
  return queue;
}


long int 
queueIsEmpty (Queue *queue) {
  return queue->qty == 0;
}


long int 
queueSize (Queue *queue) {
  return queue->qty;
}


long int
queueFront (Queue *queue) {
  return queue->head->item;
}


void 
queueEnqueue (long int item, Queue *queue) {
  Node *new = malloc (sizeof(Node));
  new->item = item;
  new->next = NULL;

  if (queueIsEmpty(queue)) {
    queue->head = new;
  } else {
    queue->tail->next = new;
  }

  queue->tail = new;
  queue->qty++;
}


void
queueDequeue (Queue *queue) {
  if (queueIsEmpty(queue)) {
    printf("%s", messages[4]);
    abort();
  } else {
    Node *temp  = queue->head;
    queue->head = temp->next;
    queue->qty--;
    free(temp);
  }
}


void 
queueDisplay (Queue *queue) {
  if (queueIsEmpty(queue)) {
    printf("%s", messages[4]);
    abort();
  } else {
    Node *temp = queue->head;

    while (temp) {
      printf("%li ", temp->item);
      temp = temp->next;
    }

    putchar('\n');
  }
}


void 
queueDestroy (Queue *queue) {
  Node *aux = queue->head;

  while (aux) {
    Node *temp = aux->next;
    free(aux);
    aux = temp;
  }

  free(queue);
  queue = NULL;
}


BSTree 
*binarySearchTreeCreateNode (long int item) {
  BSTree *node = malloc(sizeof(BSTree));
  node->item  = item;
  node->left  = NULL;
  node->right = NULL;
  return node;
}


BSTree
*binarySearchTreeInsertNode (BSTree *newNode, BSTree *root) {
  if(root == NULL) {
    return newNode;
  } if (root->item > newNode->item) {
    root->left = binarySearchTreeInsertNode(newNode, root->left);
  } else {
    root->right = binarySearchTreeInsertNode(newNode, root->right);
  }

  return root;
}


BSTree 
*binarySearchTreeRemoveNode (long int key, BSTree *root) {
  BSTree *father = NULL;
  BSTree *temp   = root;

  while (temp != NULL && temp->item != key) {
    father = temp;
    if (temp->item > key) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }

  if(temp == NULL) {
    printf("%s", messages[10]);
    return root;
  }

  if (temp->right == NULL && temp->left == NULL) {
    if(temp != root) {
      if(father->left == temp) {
        father->left = NULL;
      } else {
        father->right = NULL;
      }
    } else {
      root = NULL;
    }

    free(temp);
  } 

  else if (temp->right == NULL) {
    if (temp != root) {
      if (father->left == temp) {
        father->left = temp->left;
      } else {
        father->right = temp->left;
      }
    } else {
      root = temp->left;
    }

    free(temp);
  }

  else if (temp->left == NULL) {
    if (temp != root) { 
      if (father->left == temp) {
        father->left = temp->right;
      } else {
        father->right = temp->right; 
      }
    } else {
      root = temp->right;
    }

    free(temp);
  }

  else {
    BSTree *aux = temp->left;
    father = NULL;

    while (aux->right != NULL) {
      father = aux;
      aux = aux->right;
    }

    if (father != NULL) {
      father->right = aux->left;
    } else {
      temp->left = aux->left;
    }

    temp->item = aux->item;
    free(aux);
  }

  return root;
}


long int 
binarySearchTreeIsEmpty (BSTree *root) {
  return (root == NULL);
}


void 
binarySearchTreeDisplayPreOrder (BSTree *root) {
  if (root) {
    printf("%li\n",root->item);
    binarySearchTreeDisplayPreOrder(root->left);
    binarySearchTreeDisplayPreOrder(root->right);
  }
}


void 
binarySearchTreeDisplayInOrder (BSTree *root) {
  if (root) {
    binarySearchTreeDisplayInOrder(root->left);
    printf("%li\n",root->item);
    binarySearchTreeDisplayInOrder(root->right);
  }
}


void 
binarySearchTreeDisplayPostOrder (BSTree *root) {
  if (root) {
    binarySearchTreeDisplayPostOrder(root->left);
    binarySearchTreeDisplayPostOrder(root->right);
    printf("%li\n",root->item);
  }
}


void 
binarySearchTreePadding (char ch, long int n) {
  for (long int i = 0; i < n; i++ ) {
    putchar(ch);
  }
}


void 
binarySearchTreeDisplayTree (long int level, BSTree *root) {
  if (root == NULL) {
    binarySearchTreePadding('\t', level);
    puts("~");
  } else {
    binarySearchTreeDisplayTree(level + 1, root->right);
    binarySearchTreePadding('\t', level);
    printf("%li\n", root->item);
    binarySearchTreeDisplayTree(level + 1, root->left);
  }
}


long int 
binarySearchTreeGetItem (BSTree *root) {
  return root->item;
}


long int 
binarySearchTreeItemExists (long int item, BSTree *root) {
  if (root == NULL) {
    return 0;
  } if(root->item == item) {
    return 1;
  } else if (binarySearchTreeItemExists(item, root->left)) {
    return 1;
  } else {
    return binarySearchTreeItemExists(item, root->right);
  }
}


BSTree 
*binarySearchTreeSearch (long int key, BSTree *root) {
  if (root == NULL || root->item == key) { 
    return root; 
  }

  if (root->item > key) {
    return binarySearchTreeSearch(key, root->left);
  } else {
    return binarySearchTreeSearch(key, root->right);
  }
}


long int 
binarySearchTreeTotalNodes (BSTree *root) {
  if (root == NULL) {
    return 0;
  } else  {
    return binarySearchTreeTotalNodes(root->left) + \
    binarySearchTreeTotalNodes(root->right) + 1;
  }
}


long int 
binarySearchTreeHeight (BSTree *root) {
  if (root == NULL) {
    return -1;
  }

  long int hSTL = binarySearchTreeHeight(root->left);
  long int hSTR = binarySearchTreeHeight(root->right);

  if (hSTL > hSTR) {
    return hSTL + 1;
  } else {
    return hSTR + 1;
  }
}


long int 
binarySearchTreeIsBalanced (BSTree *root) {
  if (root == NULL) { 
    return 1; 
  } else if (!binarySearchTreeIsBalanced(root->left)) {
    return 0;
  } else if (!binarySearchTreeIsBalanced(root->right)) {
    return 0;
  } else if (abs((int) binarySearchTreeHeight(root->left) - \
    (int)binarySearchTreeHeight(root->right)) > 1) {
    return 0;
  }

  return 1;
}


long int 
binarySearchTreeTotalLeafs (BSTree *root) {
  if (root == NULL) {
    return 0;
  } else if (root->left == NULL && root->right == NULL) { 
    return 1; 
  }

  return binarySearchTreeTotalLeafs(root->left) + \
  binarySearchTreeTotalLeafs(root->right);
}


BSTree 
*binarySearchTreeFindMin (BSTree *root) {
  if (root == NULL) { 
    return NULL; 
  } else if (root->left == NULL) { 
    return root; 
  } else { 
    return binarySearchTreeFindMin(root->left); 
  }
}


BSTree 
*binarySearchTreeFindMax (BSTree *root) {
  if (root == NULL) { 
    return NULL; 
  } else if (root->right == NULL) { 
    return root; 
  } else { 
    return binarySearchTreeFindMax(root->right); 
  }
}


void 
binarySearchTreeDestroy (BSTree *root) {
  if (root) {
    binarySearchTreeDestroy(root->left);
    binarySearchTreeDestroy(root->right);
    free(root);
    root = NULL;
  } 
}


List 
*linkedListCreate () {
  List *list = malloc (sizeof(List));
  list->head = NULL;
  list->head = list->tail =  NULL;
  list->qty = 0;
  return list; 
}


void 
linkedListInsertItemBegin (long int item, List *list) {
  Node *node = malloc (sizeof(Node));
  node->item = item;
  node->next = list->head;

  if (list->tail == NULL) {
    list->tail = node;
  } else {
    list->head->prev = node;
  }

  list->head = node;
  list->qty++;
}


void 
linkedListInsertItemEnd (long int item, List *list) {
  Node *node = malloc (sizeof(Node));
  node->item = item;
  node->next = NULL;
  node->prev = list->tail;

  if (list->tail == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }

  list->tail = node;
  list->qty++;
}


void 
linkedListDisplay (List *list) {
  Node *node = list->head;

  while (node != NULL) {
    printf("%li -> ", node->item);
    node = node->next;
  }

  printf("NULL\n");
}


void 
linkedListReverseDisplay (List *list) {
  Node *node = list->tail;

  while (node != NULL) {
    printf("%li -> ", node->item);
    node = node->prev;
  }

  printf("NULL\n");
}


Node
*linkedListHead (List *list) {
  return list->head;
}


Node
*linkedListTail (List *list) {
  return list->tail;
}


long int
linkedListNode (Node *index) {
  if (index != NULL) {
    return index->item;
  }
}


Node
*linkedListSearch (long int item, List *list) {
  if(linkedListIsEmpty(list)) { return NULL; }

  Node *node = list->head;

  while (node && node->item != item) {
    node = node->next;
  }
      
  return node;
}


long int 
linkedListSize (List *list) {
  return list->qty;
} 


long int 
linkedListIsEmpty (List *list) {
  return list->head == NULL;
}


void
linkedListRemove (long int item, List *list) {
  if(linkedListIsEmpty(list)) { return; }

  Node *node = linkedListSearch(item, list);

  if (node == NULL) {
    return;
  } if (node == list->head) {
    list->head = node->next;
  } else {
    node->prev->next = node->next;
  } if (node == list->tail) {
    list->tail = node->prev;
  } else {
    node->next->prev = node->prev;
  }

  list->qty--;
  free(node);
  node = NULL;
}


void 
linkedListDestroy (List *list) {
  Node *node = list->head;

  while (node != NULL) {
    Node *temp = node->next;
    free(node);
    node = temp;
  }

  free(list);
  list = NULL;
}


Map 
mapCreate (long int key, char *value, Map index) {
  Map node = malloc(sizeof(struct map));
  node->key = key;
  strcpy(node->value, value);
  node->next = index;
  return node;
}


void 
mapInsert (long int key, char *value, Map *index) {
  while (*index != NULL && (*index)->key < *value) {
    index = &(*index)->next;
  } if (*index != NULL && (*index)->key == *value) {
    strcpy((*index)->value, value);
  } else {
    *index = mapCreate(key, value, *index);
  }
}


long int 
mapRemove (long int key, Map *index) {
  while (*index != NULL && (*index)->key < key) {
    index = &(*index)->next;
  } if (*index == NULL || (*index)->key > key) {
    return 0;
  }

  Map node = *index;
  *index = node->next;
  free(node);
  return 1;
}


long int 
mapKeyExists (long int key, Map index) {
  while (index != NULL && index->key < key) {
    index = index->next;
  }

  return (index != NULL && index->key == key);
}


void 
mapDisplay (Map index) {
  printf("{\n");
  while(index != NULL) {
    printf("[%li, %s]", index->key, index->value);
    if (index->next != NULL) {
      printf(",\n");
    }

    index = index->next;
  }

  printf("\n}\n");
}


void 
mapDestroy (Map *index) {
  while ((*index) != NULL) {
    Map node = *index;
    *index = node->next;
    free(node);
  }
}


Hufftree 
hufftreeCreateNode (Hufftree left, char chr, long int frq, Hufftree right) {
  Hufftree index = malloc(sizeof(struct htree));
  index->left  = left;
  index->chr   = chr;
  index->frq   = frq;
  index->right = right;
  return index;
}


long int 
*hufftreeFrequency (char *string) {
  static long int array[FREQ];

  for (long int i = 0; i < FREQ; i++) {
    array[i] = 0;
  } 

  for (long int i = 0; string[i]; i++) {
    array[string[i]]++;
  }

  return array;
}


void 
hufftreeInsert (Hufftree tree, Hufftree *forest, long int *qty) {
  long int i = *qty;

  while(i > 0 && forest[i - 1]->frq < tree->frq) {
    forest[i] = forest[i - 1];
    i--;
  }

  forest[i] = tree;
  (*qty)++;
}


Hufftree 
hufftreeRemove (Hufftree *forest, long int *qty) {
  if (*qty == 0) { abort(); }
  return forest[--(*qty)];
}


Hufftree 
hufftreeCreate (char *string) {
  Hufftree forest[FREQ];
  long int qty = 0;
  long int *leaf = hufftreeFrequency(string);

  for (long int chr = 0; chr < FREQ; chr++) {
    if (leaf[chr] > 0) {
      hufftreeInsert(hufftreeCreateNode(NULL, chr, leaf[chr], NULL),
      forest, &qty);
    }
  }

  while (qty > 1) {
    Hufftree right = hufftreeRemove(forest, &qty);
    Hufftree left  = hufftreeRemove(forest, &qty);
    hufftreeInsert(hufftreeCreateNode(left, '-', left->frq + right->frq, right),
    forest, &qty);
  }

  return forest[0];
}


void 
hufftreeDisplay (Hufftree tree) {
  static long int node = -1;

  if (tree == NULL) { return; }

  node++;

  hufftreeDisplay(tree->right);

  for (long int i = 0; i < HCOL * node; i++) {
    putchar(' ');
  }

  printf("(%c, %li)\n", tree->chr, tree->frq);

  hufftreeDisplay(tree->left);

  node--;
}


void 
hufftreeDisplayLeaves (Hufftree tree) {
  static char array[FREQ], last = -1;

  if (tree == NULL) { return; }
  if (tree->left == NULL && tree->right == NULL) {
    printf("%c : %.*s\n", tree->chr, last + 1, array);
  } else {
    last++; 
    array[last] = '0'; hufftreeDisplayLeaves(tree->left);
    array[last] = '1'; hufftreeDisplayLeaves(tree->right);
    last--;
  }
}


void 
hufftreeCreateTable (Hufftree tree, char *T[]) {
  static char array[FREQ], last = -1;
  if (tree == NULL) { return; }
  if (tree->left == NULL && tree->right == NULL) {
    T[tree->chr] = strndup(array, last+1);
  } else {
    last++;
    array[last] = '0'; hufftreeCreateTable(tree->left, T);
    array[last] = '1'; hufftreeCreateTable(tree->right, T);
    last--;
  }
}


void 
hufftreeCompressString (char *string, Hufftree tree) {
  char *T[FREQ];

  for (long int chr = 0; chr < FREQ; chr++) {
    T[chr] = NULL;
  }

  hufftreeCreateTable(tree, T);

  for (long int i = 0; string[i]; i++) {
    printf("%s", T[string[i]]);
  }

  for (long int chr = 0; chr < FREQ; chr++) {
    free(T[chr]);
  }
}


void 
hufftreeDecompressString (char *string, Hufftree tree) {
  if (tree == NULL) { return; }
  Hufftree root = tree;

  for (long int i = 0; string[i]; i++) {
   if (string[i] == '0') {
    root = root->left;
   } else {
    root = root->right;
   }

   if (root->left == NULL && root->right == NULL) {
    printf("%c", root->chr);
    root = tree;
   }
  }
}


void 
hufftreeDestroy (Hufftree tree) {
  if (tree) {
    hufftreeDestroy(tree->left);
    hufftreeDestroy(tree->right);
    free(tree);
  }
}


Set 
*setCreate (long int max) {
  Set *set = malloc (sizeof(Set));
  set->values = malloc (max * sizeof(Set));
  set->size = 0;

  return set;
}


void 
setInsert (long int item, Set *set) {
  if (setSearch(item, set) == -1) {
    set->values[set->size] = item;
    set->size++;
  } else {
    return;
  }
}


void 
setRemove (long int item, Set *set) {
  if (setSearch(item, set) == -1 || setIsEmpty(set)) {
    printf("%s", messages[9]);
    return;
  } else {
    long int index = -1;
    for (long int i = 0; i < set->size; i++) {
      if (set->values[i] == item) {
        index = i;
        break;
      }
    } 

    if (index != -1) {
      for (long int i = index; i < set->size - 1; i++) {
        set->values[i] = set->values[i + 1];
      }

      set->size--;
    } else {
      printf("%s", messages[9]);
      return;
    }
  }
}


Set 
*setUnion (Set *A, Set *B) {
  Set *C = setCreate((A->size + B->size));

  for (long int i = 0; i < A->size; i++) {
    setInsert(A->values[i], C);
  }

  for (long int i = 0; i < B->size; i++) {
    setInsert(B->values[i], C);
  }

  return C;
}


Set 
*setIntersection (Set *A, Set *B) {
  long int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = setCreate(max);

  for (long int i = 0; i < max; i++) {
    if (setSearch(B->values[i], A) != -1) {
      C->values[C->size++] = B->values[i];
    }
  }

  return C;
}


Set 
*setDifference (Set *A, Set *B) {
  long int max = (A->size >= B->size) ? A->size : B->size;

  Set *C = setCreate(max);

  for (long int i = 0; i < max; i++) {
    if (setSearch(A->values[i], B) == -1) {
      C->values[C->size++] = A->values[i];
    }
  }

  return C;
}


long int 
setSize (Set *set) {
  return set->size;
}


long int 
setHighestValue (Set *set) {
  long int value = 0;

  for (long int i = 0; i < set->size; i++) {
    if (set->values[i] > value) {
      value = set->values[i];
    }
  }

  return value;
}


long int 
setLowestValue (Set *set) {
  long int value = 1;

  for (long int i = 0; i < set->size; i++) {
    if (set->values[i] < value) {
      value = set->values[i];
    }
  }

  return value;
}


long int 
setIsEmpty (Set *set) {
  return (set->size == 0);
}


long int 
setSearch (long int item, Set *set) {
  for (long int i = 0; i < set->size; i++) {
    if (set->values[i] == item) {
      return set->values[i];
    }
  }

  return -1;
}


void 
setDisplay (Set *set) {
  printf("{ ");
  for (long int i = 0; i < set->size; i++) {
    printf("%li ", set->values[i]);
  }

  printf("}\n");
}


void 
setDestroy (Set *set) {
  free(set->values);
  free(set);

  set = NULL;
}


PrioQ 
*priorityQueueCreate () {
  PrioQ *queue = malloc (sizeof(PrioQ));
  queue->first = queue->last = queue->qty = 0;
  return queue;
}


void 
priorityQueueInsert (long int value, PrioQ *queue) {
  if (queue == NULL) return;

  if (!priorityQueueIsFull(queue)) {
    long int index = queue->qty - 1;
    while (index >= 0 && queue->pvalue_t[index].prio >= value) {
      queue->pvalue_t[index + 1] = queue->pvalue_t[index];
      index--;
    }

    queue->pvalue_t[index + 1].prio = value;
    queue->qty++;
  } else {
    printf("%s", messages[3]);
    exit(1);
  }
}


void 
priorityQueueRemoveHighestPrio (PrioQ *queue) {
  if (!priorityQueueIsEmpty(queue) || queue != NULL) {
   queue->qty--;
  }
}


long int 
priorityQueueFirst (PrioQ *queue) {
  return queue->pvalue_t[queue->qty - 1].prio;
}


bool 
priorityQueueIsEmpty (PrioQ *queue) {
  return queue->qty == 0;
}


bool 
priorityQueueIsFull (PrioQ *queue) {
  return queue->qty == SIZE;
}


long int 
priorityQueueSize (PrioQ *queue) {
  return queue->qty;
}


void 
priorityQueueDestroy (PrioQ *queue) {
  free(queue);
  queue = NULL;
}
