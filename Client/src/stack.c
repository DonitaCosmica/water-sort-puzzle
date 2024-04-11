#include "../include/stack.h"

tNodeStack *newStackNode(char element)
{
  tNodeStack *node = (tNodeStack *)malloc(sizeof(tNodeStack));

  node->element = element;
  node->prev = NULL;

  return node;
}

tStack newStack()
{
  tStack stack = (tStack)malloc(sizeof(Stack));

  stack->top = NULL;
  stack->size = 0;

  return stack;
}

bool isStackFull(tStack stack)
{
  return SMAX == stack->size;
}

bool isStackEmpty(tStack stack)
{
  return stack->size == 0;
}

void destroyStack(tStack stack)
{
  free(stack);
  printf("Stack destruido\n");
}

void push(tStack stack, char element)
{
  if(!isStackFull(stack))
  {
    tNodeStack *node = newStackNode(element);

    node->prev = stack->top;
    stack->top = node;
    stack->size++;
  }
  else
    printf("El stack esta lleno\n");
}

char pop(tStack stack)
{
  if(!isStackEmpty(stack))
  {
    tNodeStack *node = stack->top;
    stack->top = node->prev;

    char element = node->element;
    free(node);
    stack->size--;
    return element;
  }
  else
  {
    printf("El stack esta vacio\n");
    return 0;
  }
}

void printStack(tStack stack)
{
  if(!isStackEmpty(stack))
  {
    tNodeStack *node = stack->top;

    while(node != NULL)
    {
      printf("Element: %c\n", node->element);
      node = node->prev;
    }
  }
  else
    printf("No se puede mostrar el stack porque esta vacio\n");
}
