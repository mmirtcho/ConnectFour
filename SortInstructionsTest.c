#include "connectfour.h"

void SortInstructions(){
  int i;
  int j;
  int k;
  int tempeval[10];
  char tempname[10][10];
  int score = highscoreval[ihighscore-1];
  char name[10];
  if(ihighscore==1){
    return;
  }
  for(i=0;highscorename[ihighscore-1][i] != '\0' && i<strlen(highscorename[ihighscore-1]);i++){
    name[i]=highscorename[ihighscore-1][i];
  }
  name[i]='\0';
  for(i=0;i<ihighscore-1;i++){
    if(highscoreval[i]<score){
      break;
    }
  }
  for(j=ihighscore-2;j>=i;j--){
    for(k=0;k<strlen(highscorename[j]);k++){
      highscorename[j+1][k]=highscorename[j][k];
    }
    for(;k<10;k++){
      highscorename[j+1][k]='\0';
    }
    highscoreval[j+1]=highscoreval[j];
  }
  for(j=0;name[j]!='\0' && j<strlen(name);j++){
    highscorename[i][j]=name[j];
  }
  highscorename[i][j]='\0';
  highscoreval[i]=score;
}


int main()
{
  SortInstructions();
  return 0;
}
