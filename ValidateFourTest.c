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
int main()
{
  
  return 0;
}
