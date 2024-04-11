#include "./include/stack.h"
#include "./include/listColors.h"

#define RED (1 << 0)
#define GREEN (1 << 1)
#define YELLOW (1 << 2)
#define BLUE (1 << 3)
#define MAGENTA (1 << 4)
#define CYAN (1 << 5)

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
  int i;
  tGame *game = (tGame *)malloc(sizeof(tGame));

  game->stacks = (tStack *)malloc(sizeof(tStack) * TMAX);
  game->list = newList();
  game->isWinner = false;
  if(game->stacks == NULL) return NULL;

  for(i = 0; i < TMAX; i++)
    game->stacks[i] = newStack();

  for(i = 0; i < CMAX; i++)
    addNode(game->list, i);

  return game;
}

char getColorFromMask(unsigned int mask)
{
  if(mask == 0)
    return ' ';

  unsigned int bitPosition = 0;
  while((mask & (1 << bitPosition)) == 0)
    bitPosition++;

  switch (bitPosition)
  {
    case 0: return 'R';
    case 1: return 'G';
    case 2: return 'Y';
    case 3: return 'B';
    case 4: return 'M';
    case 5: return 'C';
    default: return ' ';
  }
}

int main(int argc, char *argv[])
{
  int i;
  tGame *game = startGame();

  if(game == NULL)
  {
    printf("Erroral asignar memoria al arreglo\n");
    return EXIT_FAILURE;
  }

  for(i = 0; i < TMAX; i++)
    game->stacks[i] = newStack();

  deleteNode(game->list, 'Y');

  printList(game->list);

  destroyList(game->list);

  for(i = 0; i < TMAX; i++)
    destroyStack(game->stacks[i]);

  free(game->stacks);

  return EXIT_SUCCESS;
}
