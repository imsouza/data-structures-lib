#include "dslib.h"

Queue 
*queueCreate () {
  Queue *queue  = mallocSafe (sizeof(Queue));
  queue->head = queue->tail = NULL;
  queue->qty = 0;
  return queue;
}


bool 
queueIsEmpty (Queue *queue) {
  return queue->qty == 0;
}


int 
queueSize (Queue *queue) {
  return queue->qty;
}


int
queueFront (Queue *queue) {
  return queue->head->item;
}


void 
queueEnqueue (int item, Queue *queue) {
  Queue *new = mallocSafe (sizeof(Queue));
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
    exit(1);
  } else {
    Queue *temp  = queue->head;
    queue->head = temp->next;
    queue->qty--;
    free(temp);
  }
}


void 
queueDisplay (Queue *queue) {
  if (queueIsEmpty(queue)) {
    exit(1);
  } else {
    Queue *temp = queue->head;

    while (temp) {
      printf("%i ", temp->item);
      temp = temp->next;
    }

    putchar('\n');
  }
}


void 
queueDestroy (Queue *queue) {
  Queue *aux = queue->head;

  while (aux) {
    Queue *temp = aux->next;
    free(aux);
    aux = temp;
  }

  free(queue);
  queue = NULL;
}