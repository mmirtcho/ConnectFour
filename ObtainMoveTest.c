#include "connectfour.h"

int ObtainMove(){
  int result =0;
  int iColumn;
  int n;
  char buffer[maxsize];

  printf("\n");
  do{
    printf("Please enter your move: \n");
    scanf("%s", buffer);
    iColumn=atoi(buffer);
    if (iColumn > 7 || iColumn < 1)
      printf("Invalid column\n");
    else if (aMain[iColumn][6] != ' ')
      printf("The column is full\n");
    else
      result = iColumn;
  }while (result==0);
  return result;
}

int main()
{
	int i,j;

    for (i = 1; i <= 7; i++){
        for (j = 1; j <= 6; j++){
            aMain[i][j] = ' ';
        }
    }

  int x=ObtainMove();
  printf("Move you entered was: ");
  printf("%d. \n",x);
  return 0;
}
