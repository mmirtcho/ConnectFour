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
	int i,j;

    for (i = 1; i <= 7; i++){
        for (j = 1; j <= 6; j++){
            aMain[i][j] = ' ';
        }
    }

  displayGrid();
  sColor='R';
  MakeMove(4);
  sColor='B';
  MakeMove(3);
  sColor='R';
  MakeMove(4);
  sColor='B';
  MakeMove(2);

  printf("This is how making moves 4 - 3 - 4 - 2 look like \n");

  return 0;
}
