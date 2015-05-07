#include "connectfour.h"


int ValidateFour(int Col, int Row, char WHO )
{

  int i;
  int j;
  int k;
  int iValidateFour;
  int jMax;
  int jMin;
  int iMin;
  int iMax;

  //1. Validate horizontal
  iValidateFour = 1;

  for( i = aHELPER[Col][Row].HorizontalLeft;i<= aHELPER[Col][Row].HorizontalRight;i++)
    {
      k=0;
      //s = ' ';
      for( j = i;j<= i + 3;j++){
	if (aMain[j][Row]==WHO){
	  k++;
	}
      }
      if (k == 4)
	{
	  return iValidateFour;
	}
    }
  //2. Validate vertical
  if(Row > 3)
    {
      k=0;
      //s = ' ';
      for (j = Row - 3;j<=Row;j++){
	if(WHO==aMain[Col][j]){
	  k++;
	}
      }
      if (k == 4)
        {
	  return iValidateFour;
        }
    }
  //3. Validate diagonal +
  jMin=aHELPER[Col][Row].PositiveDiagonalBottomROW;
  if(jMin > 0)
    {
      jMax=aHELPER[Col][Row].PositiveDiagonalTopROW;

      for (j = jMin;j<=jMax;j++){
	iMin = aHELPER[Col][Row].PositiveDiagonalBottomCOL;
	iMax = aHELPER[Col][Row].PositiveDiagonalBottomCOL+3;
	k=0;
	for (i = iMin; i<=iMax; i++){
	  if (aMain[i+(j-jMin)][(j + (i - iMin))]==WHO){
	    k++;
	  }
	}
	if (k == 4){
	  return iValidateFour;
	}
      }
    }
  //'4. Validate diagonal -
  jMin=aHELPER[Col][Row].NegativeDiagonalBottomROW;
  if (jMin > 0){
    jMax=aHELPER[Col][Row].NegativeDiagonalTopROW;
    for (j = jMin; j<=jMax; j++){
      iMin=aHELPER[Col][Row].NegativeDiagonalBottomCOL;
      iMax=iMin-3;
      k=0;
      for (i = iMin; i>=iMax; i--){
	if (aMain[i - (j - jMin)][(j + (iMin - i))]==WHO){
	  k++;
	}
      }
      if (k == 4){
	return iValidateFour;
      }
    }
  }
  return 0;
}

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
 if(ValidateFour(4,5,'B')==1){
            printf("Game Over! Player has won!\n");
}
else{
printf("FAIL!\n");
}
  return 0;
}




