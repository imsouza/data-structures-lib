#include "dslib.h"

struct pvalue {
  int prio;
};


struct prioq {
  int first;
  int last;
  int qty;
  struct pvalue pvalue_t[SIZE];
};


PrioQ 
*priorityQueueCreate () {
  PrioQ *queue = mallocSafe (sizeof(PrioQ));
  queue->first = queue->last = queue->qty = 0;
  return queue;
}


void 
priorityQueueInsert (int value, PrioQ *queue) {
  if (queue == NULL) return;

  if (!priorityQueueIsFull(queue)) {
    int index = queue->qty - 1;
    while (index >= 0 && queue->pvalue_t[index].prio >= value) {
      queue->pvalue_t[index + 1] = queue->pvalue_t[index];
      index--;
    }

    queue->pvalue_t[index + 1].prio = value;
    queue->qty++;
  } else {
    exit(1);
  }
}


void 
priorityQueueRemoveHighestPrio (PrioQ *queue) {
  if (!priorityQueueIsEmpty(queue) || queue != NULL) {
   queue->qty--;
  }
}


int 
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


int 
priorityQueueSize (PrioQ *queue) {
  return queue->qty;
}


void 
priorityQueueDestroy (PrioQ *queue) {
  free(queue);
  queue = NULL;
}