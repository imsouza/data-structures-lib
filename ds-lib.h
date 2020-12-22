typedef struct stack {
  int max;
  int top;
  char *item;
} *Stack;


static const char * const messages[] = {
    "[!] Stack overflow!\n",
    "[!] Stack underflow!\n",
    "[!] Empty stack!\n"
};


Stack stack (int max) {
  Stack this = malloc(sizeof(struct stack));
  this->max  = max;
  this->top  = -1;
  this->item = malloc(max * sizeof(char));
  return this;
}


int emptyStack (Stack this) {
  if (this->top == -1) {
    return 1;
  } else {
    return 0;
  }
}


int fullStack (Stack this) {
  if (this->top == this->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


void stackPush (char element, Stack this) {
  if (fullStack(this)) {
    printf("%s", messages[0]);
    abort();
  } else {
    this->top++;
    this->item[this->top] = element;
  }
}


char stackPop (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[1]);
    abort();
  } else {
    char element = this->item[this->top];
    this->top--;
    return element;
  }
}


char stackTop (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return this->item[this->top];
  }
}


int stackSize (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return this->top + 1;
  }
}


void displayStack (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    for (int i = 0; i <= this->top; i++) {
      printf("%i\n", this->item[i]);
    }
  }
}


void displayReverseStack (Stack this) {
  if (emptyStack(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    for (int i = this->top; i >= 0; i--) {
      printf("%i\n", this->item[i]);
    }
  }
}


void deleteStack (Stack *this) {
  free((*this)->item);
  free(*this);
  *this = NULL;
}
