#include "../include/listColors.h"

tList newList()
{
  tList list = (tList)malloc(sizeof(List));

  list->head = NULL;
  list->size = 0;

  return list;
}

tNodeList *newListNode(unsigned short bitPosition)
{
  tNodeList *node = (tNodeList *)malloc(sizeof(tNodeList));
  node->limit = BMAX;
  node->colorPosition = (1 << bitPosition);

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
  printf("Lista destruida\n");
}

void addNode(tList list, unsigned short bitPosition)
{
  if(!isListFull(list))
  {
    tNodeList *node = newListNode(bitPosition);

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
  else
    printf("La lista esta llena\n");
}

void deleteNode(tList list, char color)
{
  if(!isListEmpty(list))
  {
    tNodeList *prev = NULL;
    tNodeList *aux = list->head;

    while(aux != NULL && aux->color != color)
    {
      prev = aux;
      aux = aux->sig;
    }

    if(aux != NULL)
    {
      if(prev != NULL)
        prev->sig = aux->sig;
      else
        list->head = aux->sig;

      free(aux);
    }
    else
      printf("No se encontro el color\n");
  }
  else
    printf("La lista esta vacia\n");
}

void printList(tList list)
{
  if(!isListEmpty(list))
  {
    tNodeList *aux = list->head;

    while(aux != NULL)
    {
      printf("Color: %c\n", aux->color);
      printf("Limit: %hu\n", aux->limit);
      printf("Color Position: %u\n", aux->colorPosition);
      aux = aux->sig;
    }
  }
  else
    printf("No se puede imprimir una lista vacia\n");
}
