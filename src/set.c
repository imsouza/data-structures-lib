#include "dslib.h"

struct set {
  int *values;
  int size;
};


Set 
*setCreate (int max) {
  Set *set = mallocSafe (sizeof(Set));
  set->values = mallocSafe (max * sizeof(Set));
  set->size = 0;
  return set;
}


void 
setInsert (int item, Set *set) {
  if (setSearch(item, set) == NULL) {
    set->values[set->size] = item;
    set->size++;
  } else {
    return;
  }
}


void 
setRemove (int item, Set *set) {
  if (setSearch(item, set) == NULL || setIsEmpty(set)) {
    exit(1);
  } else {
    int index = -1;
    for (int i = 0; i < set->size; i++) {
      if (set->values[i] == item) {
        index = i;
        break;
      }
    } 

    if (index != -1) {
      for (int i = index; i < set->size - 1; i++) {
        set->values[i] = set->values[i + 1];
      }

      set->size--;
    } else {
      exit(1);
    }
  }
}


Set 
*setUnion (Set *A, Set *B) {
  int max = SET_MAX(A, B);

  Set *C = setCreate(max);

  for (int i = 0; i < A->size; i++) {
    setInsert(A->values[i], C);
  }

  for (int i = 0; i < B->size; i++) {
    setInsert(B->values[i], C);
  }
  
  return C;
}


Set 
*setIntersection (Set *A, Set *B) {
  int max = SET_MAX(A, B);

  Set *C = setCreate(max);

  for (int i = 0; i < max; i++) {
    if (setSearch(B->values[i], A) != NULL) {
      C->values[C->size++] = B->values[i];
    }
  }

  return C;
}


Set 
*setDifference (Set *A, Set *B) {
  int max = SET_MAX(A, B);

  Set *C = setCreate(max);

  for (int i = 0; i < max; i++) {
    if (setSearch(A->values[i], B) == NULL) {
      C->values[C->size++] = A->values[i];
    }
  }

  return C;
}


int 
setSize (Set *set) {
  return set->size;
}


int 
setHighestValue (Set *set) {
  int value = set->values[0];

  for (int i = 0; i < set->size; i++) {
    if (set->values[i] > value) {
      value = set->values[i];
    }
  }

  return value;
}


int 
setLowestValue (Set *set) {
  int value = set->values[0];

  for (int i = 0; i < set->size; i++) {
    if (set->values[i] < value) {
      value = set->values[i];
    }
  }

  return value;
}


bool 
setIsEmpty (Set *set) {
  return (set->size == 0);
}


int
*setSearch (int item, Set *set) {
  for (int i = 0; i < set->size; i++) {
    if (set->values[i] == item) {
      return &set->values[i];
    }
  }

  return NULL;
}


void 
setDisplay (Set *set) {
  int H[set->size];

  for (int i = 0; i < set->size; i++) {
    H[i] = set->values[i];
  }
  
  heapSort(H, set->size);

  printf("{ ");
  for (int i = 0; i < set->size; i++) {
    printf("%i ", H[i]);
  }

  printf("}\n");
}


void 
setCreateHeap (int *set, int father, int end) {
  int temp = set[father];
  int child = 2 * father + 1;

  while (child <= end) {
    if (child < end) {
      if (set[child] < set[child + 1]) {
        child++;
      }
    }

    if (temp < set[child]) {
      set[father] = set[child];
      father = child;
      child = 2 * father + 1;
    } else {
      child = end + 1;
    }
  }

  set[father] = temp;
}


int 
*heapSort (int *set, int size) {
  for (int i = (size - 1) / 2; i >= 0; i--) {
    setCreateHeap(set, i, size-1);
  }

  for (int i = size - 1; i >= 1; i--) {
    int temp = set[0];
    set[0] = set[i];
    set[i] = temp;
    setCreateHeap(set, 0, i-1);
  }

  return set;
}


void 
setDestroy (Set *set) {
  free(set->values);
  free(set);

  set = NULL;
}