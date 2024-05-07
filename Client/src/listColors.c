#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CMAX 6
#define BMAX 4

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

tList newList()
{
  tList list = (tList)malloc(sizeof(List));

  if(list != NULL)
  {
    list->head = NULL;
    list->size = 0;
  }

  return list;
}

static tNodeList *newNode(unsigned short bitPosition)
{
  tNodeList *node = (tNodeList *)malloc(sizeof(tNodeList));

  if(node != NULL)
  {
    node->limit = BMAX;

    switch (bitPosition)
    {
      case 0: node->color = 'R'; break;
      case 1: node->color = 'G'; break;
      case 2: node->color = 'Y'; break;
      case 3: node->color = 'B'; break;
      case 4: node->color = 'M'; break;
      case 5: node->color = 'C'; break;
      default: node->color = ' ';
    }
  }

  return node;
}

static unsigned short getRandomNodeNumber(unsigned short listSize)
{
  return (rand() % listSize);
}

bool allBallsAreUsed(tNodeList *node)
{
  return node->limit == 0;
}

bool isListFull(tList list)
{
  return list->size >= CMAX;
}

bool isListEmpty(tList list)
{
  return list == NULL || list->head == NULL;
}


char getRandomCharacter(tList list, onDeleteNode deleteCurrentNode)
{
  if(isListEmpty(list))
  {
    puts("La lista esta vacia");
    return 0;
  }

  size_t i = 0;
  unsigned short randomIndex = getRandomNodeNumber(list->size);
  tNodeList *currentNode = list->head;

  for(; i < randomIndex; i++)
    currentNode = currentNode->sig;

  currentNode->limit--;

  if(allBallsAreUsed(currentNode) && deleteCurrentNode != NULL)
  {
    char color = currentNode->color;
    deleteCurrentNode(list, currentNode->color);
    return color;
  }

  return currentNode->color;
}

void addNode(tList list, unsigned short bitPosition)
{
  if(isListFull(list))
  {
    puts("La lista esta llena");
    return;
  }

  tNodeList *node = newNode(bitPosition);
  if(node == NULL)
  {
    puts("Error al crear un nuevo nodo");
    return;
  }

  if(!isListEmpty(list))
  {
    tNodeList *aux = list->head;

    while(aux->sig != NULL)
      aux = aux->sig;

    aux->sig = node;
  }
  else
    list->head = node;

  list->size++;
}

void deleteNode(tList list, char color)
{
  if(isListEmpty(list))
  {
    puts("La lista esta vacia");
    return;
  }

  tNodeList *prev = NULL;
  tNodeList *aux = list->head;

  while(aux != NULL && aux->color != color)
  {
    prev = aux;
    aux = aux->sig;
  }

  if(aux != NULL)
  {
    (prev != NULL) ? (prev->sig = aux->sig) : (list->head = aux->sig);
    aux->sig = NULL;
    free(aux);
  }

  list->size--;
}

void destroyList(tList list)
{
  free(list);
  list = NULL;
  puts("Lista destruida");
}

void printList(tList list)
{
  if(isListEmpty(list))
  {
    puts("No se puede imprimir una lista vacia");
    return;
  }

  tNodeList *aux = list->head;
  while(aux != NULL)
  {
    printf("Color: %c\n", aux->color);
    printf("Limit: %hu\n", aux->limit);
    aux = aux->sig;
  }
}
