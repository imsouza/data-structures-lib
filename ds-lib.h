typedef struct stack {
  int max;
  int top;
  char *item;
} *Stack;


static const char* const messages[] = {
    "[!] Stack overflow!\n",
    "[!] Stack underflow!\n",
    "[!] Empty stack!\n"
};


Stack stack (int max) {
  Stack this = malloc(sizeof(struct stack));
  this->max = max;
  this->top = -1;
  this->item = malloc(max * sizeof(char));
  return this;
}


int isEmpty (Stack this) {
  if (this->top == -1) {
    return 1;
  } else {
    return 0;
  }
}


int itsFull (Stack this) {
  if (this->top == this->max - 1) {
    return 1;
  } else {
    return 0;
  }
}


void push (char element, Stack this) {
  if (itsFull(this)) {
    printf("%s", messages[0]);
    abort();
  } else {
    this->top++;
    this->item[this->top] = element;
  }
}


char pop (Stack this) {
  if (isEmpty(this)) {
    printf("%s", messages[1]);
    abort();
  } else {
    char element = this->item[this->top];
    this->top--;
    return element;
  }
}


char access (Stack this) {
  if (isEmpty(this)) {
    printf("%s", messages[2]);
    abort();
  } else {
    return this->item[this->top];
  }
}


void destroy (Stack *this) {
  free((*this)->item);
  free(*this);
  *this = NULL;
}
