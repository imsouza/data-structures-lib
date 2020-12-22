#include <stdio.h>
#include <stdlib.h>
#include "../ds-lib.h"

int main () {
  printf("Stack ------------------\n");
  Stack S = stack(3);
  printf(">>> PUSH:\n");
  stackPush(1, S);
  stackPush(2, S);
  stackPush(3, S);
  printf(">>> DISPLAY:\n");
  displayStack(S);
  printf(">>> SIZE:\n");
  printf("%i\n", stackSize(S));
  printf(">>> POP:\n");
  stackPop(S);
  printf(">>> DISPLAY:\n");
  displayStack(S);
  printf(">>> SIZE:\n");
  printf("%i\n", stackSize(S));
  deleteStack(&S);

  printf("\n===============================================\n\n");

  printf("Queue ------------------\n");
  Queue Q = queue(3);
  printf(">>> ENQUEUE:\n");
  enqueue(1, Q);
  enqueue(5, Q);
  enqueue(7, Q);
  printf(">>> DISPLAY:\n");
  displayQueue(Q);
  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));
  printf(">>> DEQUEUE:\n");
  dequeue(Q);
  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));
  printf(">>> DISPLAY:\n");
  displayQueue(Q);
  dequeue(Q);
  printf(">>> SIZE:\n");
  printf("%i\n", queueSize(Q));
  printf(">>> DISPLAY:\n");
  displayQueue(Q);
  deleteQueue(&Q);

  return 0;
}