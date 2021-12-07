#include "dslib.h"

Stack 
*stackCreate () {
  Stack *stack = mallocSafe (sizeof(Stack));
  stack->head = NULL;
  stack->qty = 0;
  return stack;
}


bool 
stackIsEmpty (Stack *stack) {
  return stack->qty == 0;
}


void 
stackPush (int item, Stack *stack) {
  Stack *node = mallocSafe (sizeof(Stack));
  node->item = item;
  node->next = stack->head;
  stack->head = node;
  stack->qty++;
}


void 
stackPop (Stack *stack) {
  if (stackIsEmpty(stack)) {
    exit(1);
  } else {
    Stack *temp = stack->head;
    stack->head = temp->next;
    stack->qty--;
    free(temp);
  }
}


int
stackTop (Stack *stack) {
  if (stackIsEmpty(stack)) {
    exit(1);
  } else {
    return stack->head->item;
  }
}


int 
stackSize (Stack *stack) {
  return stack->qty;
}


void 
stackDisplay (Stack *stack) {
  if (stackIsEmpty(stack)) {
    exit(1);
  } else {
    Stack *temp = stack->head;

    while (temp) {
      printf("%i ", temp->item);
      temp = temp->next;
    }

    putchar('\n');
  }
}


void 
stackDestroy (Stack *stack) {
  Stack *aux = stack->head;

  while (aux) {
    Stack *temp = aux->next;
    free(aux);
    aux = temp;
  }

  free(stack);
  stack = NULL;
}
