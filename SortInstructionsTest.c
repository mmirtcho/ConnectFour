#include "connectfour.h"

void PrintHighScore(){
	int i;
	printf("   Name       Score\n");
	for(i=0;i<ihighscore;i++){
		printf("%d. ",i+1);
		printf("%-10s ",highscorename[i]);
		printf("%d\n", highscoreval[i]);
	}

}

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
    ihighscore=2;
    highscoreval[0]=32;
    highscoreval[1]=10;
    highscorename[0][0]='M';
    highscorename[0][1]='a';
    highscorename[0][2]='r';
    highscorename[0][3]='k';
    highscorename[0][4]='\0';
    highscorename[1][0]='V';
    highscorename[1][1]='l';
    highscorename[1][2]='a';
    highscorename[1][3]='d';
    highscorename[1][4]='\0';
	PrintHighScore();
	ihighscore++;

    highscorename[2][0]='M';
    highscorename[2][1]='i';
    highscorename[2][2]='c';
    highscorename[2][3]='h';
    highscorename[2][4]='a';
    highscorename[2][5]='e';
    highscorename[2][6]='l';
    highscorename[2][7]='\0';
    highscoreval[2]=40;
	printf("New With Michael being 40.\n");
  	SortInstructions();
	PrintHighScore();
  return 0;
}
