#include "connectfour.h"

void displayGrid()
{
  int x, y;
  for (y = 6; y > 0; y--)
    {
      printf("-----------------------------\n");

      for (x = 1; x < 8; x++)
        {
	  printf("|");
	  if(aMain[x][y] == 'R')
	    printf(" X ");
	  else if (aMain[x][y] == 'B')
	    printf(" O ");
	  else
	    printf("   ");
        }
      printf("|\n");
    }
  printf("-----------------------------\n");

  printf("  1   2   3   4   5   6   7 \n");
}

int main()
{
  displayGrid();
  return 0;
}
