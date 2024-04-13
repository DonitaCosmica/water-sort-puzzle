#ifndef STACK_H
#define STACK_H

#define SMAX 4

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeStack
{
  char element;
  struct NodeStack *prev;
} tNodeStack;

typedef struct
{
  tNodeStack *top;
  unsigned short size : 3;
} Stack;

typedef Stack* tStack;

tStack newStack();
bool isStackFull(tStack);
bool isStackEmpty(tStack);
void push(tStack, char);
char pop(tStack);
void destroyStack(tStack);
void printStack(tStack);

#endif
