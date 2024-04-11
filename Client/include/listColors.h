#ifndef LISTCOLORS_H
#define LISTCOLORS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CMAX 6
#define BMAX 4

typedef struct NodeList
{
  unsigned short limit;
  unsigned int colorPosition;
  char color;
  struct NodeList *sig;
} tNodeList;

typedef struct
{
  tNodeList *head;
  unsigned short size;
} List;

typedef List* tList;

tList newList();
bool isListFull(tList);
bool isListEmpty(tList);
bool allBallsAreUsed(tNodeList *);
void addNode(tList, unsigned short);
void deleteNode(tList, char);
void destroyList(tList);
void printList(tList);

#endif
