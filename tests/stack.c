#include <stdio.h>
#include <stdlib.h>
#include "../src/ds-lib.h"

int main () {
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

  return 0;
}