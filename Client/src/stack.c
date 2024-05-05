#include "../include/stack.h"

tStack newStack()
{
  tStack stack = (tStack)malloc(sizeof(Stack));

  if(stack != NULL)
  {
    stack->top = NULL;
    stack->size = 0;
  }

  return stack;
}

static tNodeStack *newNode(char element)
{
  tNodeStack *node = (tNodeStack *)malloc(sizeof(tNodeStack));

  if(node != NULL)
  {
    node->element = element;
    node->prev = NULL;
  }

  return node;
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
  puts("Stack destruido");
}

void push(tStack stack, char element)
{
  if(isStackFull(stack))
  {
    puts("El stack esta lleno");
    return;
  }

  tNodeStack *node = newNode(element);
  if(node == NULL)
  {
    puts("Error al crear un nodo del stack");
    return;
  }

  node->prev = stack->top;
  stack->top = node;
  stack->size++;
}

char pop(tStack stack)
{
  if(isStackEmpty(stack))
  {
    puts("El stack esta vacio");
    return -1;
  }

  tNodeStack *node = stack->top;
  stack->top = node->prev;

  char element = node->element;
  free(node);
  stack->size--;
  return element;
}

void printStack(tStack stack)
{
  if(isStackEmpty(stack))
  {
    puts("No se puede mostrar el stack porque esta vacio");
    return;
  }

  tNodeStack *node = stack->top;

  while (node != NULL)
  {
    printf("Element: %c\n", node->element);
    node = node->prev;
  }
}
