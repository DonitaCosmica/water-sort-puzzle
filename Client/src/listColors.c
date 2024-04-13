#include "../include/listColors.h"

tList newList()
{
  tList list = (tList)malloc(sizeof(List));

  list->head = NULL;
  list->size = 0;

  return list;
}

static tNodeList *newNode(unsigned short bitPosition)
{
  tNodeList *node = (tNodeList *)malloc(sizeof(tNodeList));
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

  return node;
}

static unsigned short getRandomNodeNumber(unsigned short listSize)
{
  return (rand() % listSize);
}

char getRandomCharacter(tList list)
{
  if(isListEmpty(list))
  {
    puts("La lista esta vacia");
    return -1;
  }

  int i = 0;
  unsigned short randomIndex = getRandomNodeNumber(list->size);
  tNodeList *currentNode = list->head;

  for(; i < randomIndex; i++)
    currentNode = currentNode->sig;

  currentNode->limit--;
  return currentNode->color;
}

bool allBallsAreUsed(tNodeList *node)
{
  return node->limit == 0;
}

bool isListFull(tList list)
{
  return list->size == CMAX;
}

bool isListEmpty(tList list)
{
  return list->head == NULL;
}

void destroyList(tList list)
{
  free(list);
  puts("Lista destruida");
}

void addNode(tList list, unsigned short bitPosition)
{
  if(isListFull(list))
  {
    puts("La lista esta llena");
    return;
  }
  tNodeList *node = newNode(bitPosition);

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
    free(aux);
  }
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
