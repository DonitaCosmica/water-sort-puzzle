#include "./include/stack.h"
#include "./include/listColors.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define TMAX 8

typedef struct
{
  tStack *stacks;
  tList list;
  bool isWinner;
} tGame;

tGame *startGame()
{
  int i, j;
  tGame *game = (tGame *)malloc(sizeof(tGame));

  game->stacks = (tStack *)malloc(sizeof(tStack) * TMAX);
  game->list = newList();
  game->isWinner = false;
  if(game->stacks == NULL) return NULL;

  for(i = 0; i < TMAX; i++)
    game->stacks[i] = newStack();

  for(i = 0; i < CMAX; i++)
    addNode(game->list, i);

  for(i = 0; i < TMAX; i++)
  {
    for(j = 0; j < SMAX; j++)
    {
      char element = getRandomCharacter(game->list);
      push(game->stacks[i], element);
    }
  }

  return game;
}

int main(int argc, char *argv[])
{
  int i;
  tGame *game = startGame();

  if(game == NULL)
  {
    puts("Erroral asignar memoria al arreglo");
    return EXIT_FAILURE;
  }

  for(i = 0; i < TMAX; i++)
    printStack(game->stacks[i]);

  printList(game->list);

  destroyList(game->list);

  for(i = 0; i < TMAX; i++)
    destroyStack(game->stacks[i]);

  free(game->stacks);

  return EXIT_SUCCESS;
}
