#define SIZE 256
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Map *mapCreate(int key, char *value, Map *index);
void mapInsert(int key, char *value, Map *index);
int mapRemove(int key, Map *index);
int mapKeyExists(int key, Map *index);
void mapDisplay(Map *index);
void mapDestroy(Map *index);

/*  printf("\n\n");

  printf("Map ------------------\n");
  Map *MapA = mapCreate(145, "Test Drive", NULL); 5
  mapDisplay(MapA);

  mapInsert(122, "Test 2", MapA);
  mapInsert(4, "Test 3", MapA);
  mapInsert(3, "Test 4", MapA);
  mapInsert(99, "Test 5", MapA);

  mapDisplay(MapA);

  mapRemove(4, MapA);

  mapDisplay(MapA);

  if (mapKeyExists(3, MapA)) {
    printf("Key found!\n");
  } else {
    printf("Key not found!\n");
  }

  mapDestroy(MapA);/*