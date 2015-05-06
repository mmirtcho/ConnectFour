#include "connectfour.h"

int temp;
int ObtainDifficulty(){

  int result=0;
  int iDifficulty;  
  int n;
  char buffer[maxsize];
  printf("\n");
  do{
    printf("Please enter the Difficulty (1=Easy, 10=Hard): \n");
    scanf("%s", buffer);
    iDifficulty=atoi(buffer);
    if (iDifficulty>10 || iDifficulty<1){
      printf("Invalid Difficulty.\n");
    }
    else{
      temp=iDifficulty;
      result=(iDifficulty-1)/2+10;
    }
  }while (result==0);
  return result;
}

int main()
{
  int x= ObtainDifficulty();
  printf("The %d difficulty you have entered converted to: ",temp);
  printf("%d\n", x);
  return 0;
}
