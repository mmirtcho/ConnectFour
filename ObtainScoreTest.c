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


int ObtainScore(){
  int x, y;
  int score=42;
  for (y = 6; y > 0; y--)
    {
      for (x = 1; x < 8; x++)
        {
	  if(aMain[x][y] == 'R'){
	    score--;
	  }
	  if (aMain[x][y] == 'B'){
	    score--;
	  }
	}
    }
  score=(score*100)/34+1;
  return score;
}
int main()
{
int i,j;
for (i = 1; i <= 7; i++){
        for (j = 1; j <= 6; j++){
            aMain[i][j] = ' ';
        }
    }

  sColor='R';
MakeMove(4);
  sColor='B';
MakeMove(4);
  sColor='R';
MakeMove(1);
  sColor='B';
MakeMove(1);
  sColor='R';
MakeMove(1);
  sColor='R';
MakeMove(1);
  sColor='B';
MakeMove(1);
  sColor='R';
MakeMove(1);
  sColor='B';
MakeMove(4);
  sColor='R';
MakeMove(7);
  sColor='B';
MakeMove(4);
  sColor='R';
MakeMove(7);
  sColor='B';
MakeMove(4);
  displayGrid();
  int x=ObtainScore();
printf("Your score is : %d. \n",x);
  return 0;
}
