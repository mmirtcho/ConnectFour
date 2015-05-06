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

int main(){

    PrintHighScore();

    ihighscore=1;//comment out
    highscoreval[0]=50;
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
    ihighscore++;
    PrintHighScore();
    highscoreval[1]=40;
    highscorename[2][0]='M';
    highscorename[2][1]='i';
    highscorename[2][2]='c';
    highscorename[2][3]='h';
    highscorename[2][4]='a';
    highscorename[2][5]='e';
    highscorename[2][6]='l';
    highscorename[2][7]='\0';
    highscoreval[2]=32;
    ihighscore++;
    PrintHighScore();
    return 0;


}
