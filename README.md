# Data Structures Lib

[![License](https://img.shields.io/badge/license-MIT-blue)](./license) [![Docs](https://img.shields.io/badge/docs-in%20progress-orange)](https://github.com/imsouza/data-structures-lib) [![Netlify Doc Status](https://api.netlify.com/api/v1/badges/09f24ae2-82ed-4eb3-a08b-2ef2abc658ef/deploy-status)](https://data-structures-lib.netlify.app) [![time tracker](https://wakatime.com/badge/github/imsouza/data-structures-lib.svg)](https://wakatime.com/badge/github/imsouza/data-structures-lib)

A library of data structures for academic purposes

## Features

- Efficient 
- Flexible
- Open source

## Documentation

See the project documentation online [here](https://data-structures-lib.netlify.app/).

## Table of contents

- [Usage](#usage)
- [Run](#run)
- [Todo](#todo)
- [License](#license)

## Usage

```
#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
  ...
}
```

#### Demonstrations:
Obs.: all demos can be found in this [folder](https://github.com/imsouza/data-structures-lib/tree/main/tests)

- Binary Search Tree
```
#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
  BSTree *root = NULL;
  BSTree *searched;
  BSTree *max;
  BSTree *min;

  insertNode(9, &root);
  insertNode(2, &root);
  insertNode(3, &root);
  insertNode(15, &root);
  insertNode(4, &root);
  insertNode(1, &root);
  insertNode(3, &root);
  insertNode(7, &root);
  insertNode(8, &root);

  displayPreOrder(root);
  displayInOrder(root);
  displayPostOrder(root);
  
  printf("%i\n", search(545, &root));

  printf("%i\n", getRoot(root));

  max = findMax(root);
  printf("%i\n", getNode(max));

  min = findMin(root);
  printf("%i\n", getNode(min));

  printf("%i\n", treeIsEmpty(root));

  deleteTree(root);

  return 0;
}
```

- Hufftree
```
#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
  displayHufftree(createHufftree("WORD"));

  displayLeaves(createHufftree("DRIVE"));

  char *string = "TEST";
  compressString(string, createHufftree(string));

  decompressString("010110", createHufftree(string));

  return 0;
}
```

- Linked List
```
#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
  List A = createList(3, createList(1, createList(5, NULL)));
  List B = createList(2, createList(6, createList(5, createList(8, NULL))));

  printf("%i\n", getListSize(A));

  displayList(A);

  displayReverseList(A);

  printf("%i\n", listIsEmpty(A));

  printf("%i\n", getHead(A));

  concatList(&A, &B);

  List C = createList(-1, cloneList(A));

  printf("%i\n", itemExists(10, C));

  deleteList(&A);

  return 0;
}
```

- Map
```
#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
  Map M = createMap(145, "Test Drive", NULL);

  displayMap(M);

  insertMap(122, "Test 2", &M);
  insertMap(4, "Test 3", &M);
  insertMap(3, "Test 4", &M);
  insertMap(99, "Test 5", &M);

  removeMap(4, &M);

  printf(">>> FIND KEY\n");
  if (keyExists(3, M)) {
    printf("Key found!\n");
  } else {
    printf("Key not found!\n");
  }

  deleteMap(&M);

  return 0;
}
```

- Queue
```
#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
  Queue Q = createQueue(3);

  enqueue(1, Q);
  enqueue(5, Q);
  enqueue(7, Q);

  displayQueue(Q);

  printf("%i\n", getQueueSize(Q));

  dequeue(Q);

  deleteQueue(&Q);

  return 0;
}
```

- Stack
```
#include <stdio.h>
#include <stdlib.h>
#include "ds-lib.h"

int main () {
  Stack S = stack(3);

  stackPush(1, S);
  stackPush(2, S);
  stackPush(3, S);

  displayStack(S);

  printf("%i\n", stackSize(S));

  stackPop(S);

  displayStack(S);

  printf("%i\n", stackSize(S));
  
  deleteStack(&S);

  return 0;
}
``` 

## Run

gcc <filename.c> -o exec

## TODO

- Data Structures
  - [ ] Avl tree
  - [x] Binary search tree
  - [ ] Circular linked list
  - [ ] Doubly linked list
  - [ ] Graph
  - [ ] Hash table
  - [ ] Hash table linear probing
  - [ ] Hash table linear probing lazy
  - [ ] Hash table separate chaining
  - [ ] Heap
  - [x] Huffman coding
  - [x] Linked list
  - [x] Map
  - [x] Queue
  - [ ] Set
  - [ ] Sorted linked list
  - [x] Stack
  - [ ] Stack array
  - [ ] Stack linked list

- Extra
  - [x] Configure preprocessor directives
  - [ ] Document all the code
  - [ ] Generate doxygen documentation
  - [x] Successfully passed the tests

## Author

Mateus Almeida

## Contributing

Feel free to make pull requests for code improvements

## License

This project is licensed under the [MIT](https://github.com/imsouza/data-structures-lib/blob/main/LICENSE) License.
