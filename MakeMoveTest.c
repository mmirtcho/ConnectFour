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

void MakeMove(int col){
  int i;
  for (i = 1;i<=6;i++){
    if ( aMain[col][i] == ' '){
      aMain[col][i] = sColor;
      displayGrid();
      return;
    }
  }

}
int main()
{
  displayGrid();
  MakeMove(3);
  displayGrid();
  MakeMove(4);
  displayGrid();
  MakeMove(2);
  displayGrid();

  printf("This is how making moves 3 - 4 - 2 look like \n");

  return 0;
}
