#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./include/stack.h"
#include "./include/listColors.h"

#define TMAX 8

typedef struct
{
  tStack *stacks;
  tList list;
  bool isWinner;
} tGame;

tGame *startGame()
{
  int i = 0, j;
  tGame *game = (tGame *)malloc(sizeof(tGame));
  if(game == NULL)
  {
    puts("Error al asignar memoria para el juego");
    return  NULL;
  }

  game->stacks = (tStack *)malloc(sizeof(tStack) * TMAX);
  if(game->stacks == NULL)
  {
    free(game);
    puts("Error al asignar memoria para los stacks");
    return NULL;
  }

  game->list = newList();
  if(game->list == NULL)
  {
    free(game->stacks);
    free(game);
  }

  game->isWinner = false;

  for(; i < TMAX; i++)
  {
    game->stacks[i] = newStack();
    if(game->stacks[i] == NULL)
    {
      destroyList(game->list);
      free(game->stacks);
      free(game);
      puts("Error al crear los stacks");
      return NULL;
    }
  }

  for(i = 0; i < CMAX; i++)
    addNode(game->list, i);

  for(i = 0; i < TMAX; i++)
  {
    for(j = 0; j < SMAX; j++)
    {
      if(i < 6)
      {
        char element = getRandomCharacter(game->list, deleteNode);
        if(element == '\0')
        {
          int k = 0;
          for(; k <= i; k++)
            destroyStack(game->stacks[k]);

          destroyList(game->list);
          free(game->stacks);
          free(game);
          puts("Error al obtener un caracter aleatorio");
          return NULL;
        }
        push(game->stacks[i], element);
      }
    }
  }

  return game;
}

int main(int argc, char *argv[])
{
  int i;
  srand(time(NULL));
  tGame *game = startGame();

  if(game == NULL)
  {
    puts("Erroral asignar memoria al arreglo");
    return EXIT_FAILURE;
  }

  for(i = 0; i < TMAX; i++)
    printStack(game->stacks[i]);

  destroyList(game->list);

  for(i = 0; i < TMAX; i++)
    destroyStack(game->stacks[i]);

  free(game->stacks);

  return EXIT_SUCCESS;
}
