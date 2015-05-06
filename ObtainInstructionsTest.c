#include "connectfour.h"

void ObtainInstructions(){
	char buffer [maxsize];
 	printf("\n");
	printf("Do you want to see instruction? (y/n)\n");
	scanf("%s", buffer);
	if(buffer[0]=='y' || buffer[0]=='Y'){
		printf("Welcome to our Connect Four Program\n");
		printf("Your name (9 letters) will be used to compare to our existing high scores.\n");
		printf("The difficulty can range from 1-10 and the moves can range from 1-7.\n");
		printf("Good Luck; Have Fun!\n");
	}
}

int main(){
	ObtainInstructions();
	return 0;
}
