#include "dslib.h"

List 
*linkedListCreate () {
  List *list = mallocSafe (sizeof(List));
  list->head = NULL;
  list->head = list->tail =  NULL;
  list->qty = 0;
  return list; 
}


void 
linkedListInsertItemBegin (int item, List *list) {
  List *node = mallocSafe (sizeof(List));
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
linkedListInsertItemEnd (int item, List *list) {
  List *node = mallocSafe (sizeof(List));
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
  List *node = list->head;

  while (node != NULL) {
    printf("%i -> ", node->item);
    node = node->next;
  }

  printf("NULL\n");
}


void 
linkedListReverseDisplay (List *list) {
  List *node = list->tail;

  while (node != NULL) {
    printf("%i -> ", node->item);
    node = node->prev;
  }

  printf("NULL\n");
}


List
*linkedListHead (List *list) {
  return list->head;
}


List
*linkedListTail (List *list) {
  return list->tail;
}


int
linkedListItem (List *index) {
  return index->item;
}


List
*linkedListSearch (int item, List *list) {
  if(linkedListIsEmpty(list)) { return NULL; }

  List *node = list->head;

  while (node && node->item != item) {
    node = node->next;
  }
      
  return node;
}


int 
linkedListSize (List *list) {
  return list->qty;
} 


bool 
linkedListIsEmpty (List *list) {
  return list->head == NULL;
}


void
linkedListRemove (int item, List *list) {
  if(linkedListIsEmpty(list)) { return; }

  List *node = linkedListSearch(item, list);

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
  List *node = list->head;

  while (node != NULL) {
    List *temp = node->next;
    free(node);
    node = temp;
  }

  free(list);
  list = NULL;
}