#include "connectfour.h"

void ObtainName(){
  int n;
  int i;
  char temp=1;
  char buffer [maxsize];
  printf("\n");
  while(temp){
    printf("Please enter your nickname (max 9 characters): \n");
    scanf("%s", buffer);
    if ((n=strlen(buffer))>9){
      printf("Invalid nickname. \n");
    }
    else{
      for(i=0;i<n;i++){
	highscorename[ihighscore][i]=buffer[i];
      }
      highscoreval[ihighscore]=0;
      ihighscore++;
      temp=0;
    }
  }
}

int main()
{
ihighscore=0;
  ObtainName();
  printf("Name you Entered is: %s. \n",	highscorename[ihighscore-1]);
  return 0;
}
