#ifndef LISTCOLORS_H
#define LISTCOLORS_H

#include <stdbool.h>

#define CMAX 6

typedef struct NodeList
{
  unsigned short limit : 3;
  char color;
  struct NodeList *sig;
} tNodeList;

typedef struct
{
  tNodeList *head;
  unsigned short size : 3;
} List;

typedef List* tList;
typedef void (*onDeleteNode)(tList, char);

tList newList();
bool isListFull(tList);
bool isListEmpty(tList);
bool allBallsAreUsed(tNodeList *);
char getRandomCharacter(tList, onDeleteNode);
void addNode(tList, unsigned short);
void deleteNode(tList, char);
void destroyList(tList);
void printList(tList);

#endif
