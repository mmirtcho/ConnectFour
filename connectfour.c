//Mark Mirtchouk, Vlad Ligai, and Michael John's Connect Four Program

#include "connectfour.h"


char aMain[8][7];
char piece[2]={ 'X','O'};
int NO_WAY=1;
int THE_ONLY_MOVE=2;
int GAME_IS_OVER=0;


typedef struct{
    int HorizontalLeft;
    int HorizontalRight;
    int PositiveDiagonalBottomCOL;
    int PositiveDiagonalBottomROW;
    int PositiveDiagonalTopCOL;
    int PositiveDiagonalTopROW;
    int NegativeDiagonalBottomCOL;
    int NegativeDiagonalBottomROW;
    int NegativeDiagonalTopCOL;
    int NegativeDiagonalTopROW;
}  HELPER;
HELPER aHELPER[8][7];
char iMove;
char sColor;

int Ply=1;
char WhoWin='B';
int TheMoveCol;
int TheMoveRoW;
int RedCounter[8];
int Difficulty=16;
//BELOW THIS IS .h

int maxsize=8;

void CreateHelper()
{
    int i;
    int j;
    int m;
    int n;

    for( i = 1;i<7;i++){
        for( j = 1;j<8;j++){
            if (j<4) {
                aHELPER[j][i].HorizontalLeft = 1;
            }
            else{
                aHELPER[j][i].HorizontalLeft= j - 3;
            }
            if (j>3) {
                aHELPER[j][i].HorizontalRight = 4;
            }
            else{
                aHELPER[j][i].HorizontalRight = j;

            }
            for( m = i - 3; m<=i;m++){
                if (m > 0 && m < 4){
                    n = j - (i - m);
                    if (n > 0 && n < 5){
                        if(    aHELPER[j][i].PositiveDiagonalBottomROW == 0){
                            aHELPER[j][i].PositiveDiagonalBottomROW = m;
                            aHELPER[j][i].PositiveDiagonalBottomCOL = n;
                        }
                        if( m + 3 < 7 && n + 3 < 8 ){
                            aHELPER[j][i].PositiveDiagonalTopROW = m;
                            aHELPER[j][i].PositiveDiagonalTopCOL = n;
                        }
                    }
                }
            }
            for( m = i - 3;m<= i;m++){
                if( m > 0 && m < 4){
                    n = j - (m - i);
                    if( n > 3 && n < 8){
                        if (aHELPER[j][i].NegativeDiagonalBottomCOL == 0){
                            aHELPER[j][i].NegativeDiagonalBottomCOL = n;
                            aHELPER[j][i].NegativeDiagonalBottomROW = m;
                        }
                        if( m > 0 && n < 8){
                            aHELPER[j][i].NegativeDiagonalTopCOL = n;
                            aHELPER[j][i].NegativeDiagonalTopROW = m;
                        }
                    }
                }
            }
        }
    }
}
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

int MakeTheBestMove()
{
    int i;
    int j;

    int iMakeTheBestMove;
//'1. Can I win Immediately?
    for (i = 1; i<=7; i++){
         for (j = 1; j<=6; j++){
            if (aMain[i][j] == ' '){
                aMain[i][j] = 'R';
                if (ValidateFour(i, j, 'R')==1){
                    aMain[i][j] = ' ';
                    if (Ply == 1) {
                        TheMoveCol = i;
                        printf("Game Over!, Computer Wins\n");
                        GAME_IS_OVER=1;
                        WhoWin = 'R';
                        return NO_WAY;
                    }
                    else
                        {
                        iMakeTheBestMove = NO_WAY;
                        WhoWin = 'R';
                        return iMakeTheBestMove;
                        }
                }
                else{
                    aMain[i][j] = ' ';
                    j=7;
                    break;
                }
            }
         }
    }

//'2. Do I have to close 3
   for (i = 1; i<=7; i++){
         for (j = 1; j<=6; j++){
            if (aMain[i][j] == ' ') {
                aMain[i][j] = 'B';
                if (ValidateFour(i, j, 'B')==1){
                    aMain[i][j] = 'R';
                    if (Ply == 1){
                        aMain[i][j] = ' ';
                        TheMoveCol = i;
                        WhoWin = 'R';
                    }
                    else{
                        Ply = Ply + 1;
                        switch (AssumeHisMove()){
                            case 1:
                                aMain[i][j] = ' ';
                                Ply = Ply - 1;
                                iMakeTheBestMove = NO_WAY;
                                return iMakeTheBestMove;
                                break;
                            case 2:
                                switch (MakeTheBestMove()){
                                    case 1:
                                        aMain[i][j] = ' ';
                                        Ply = Ply - 1;
                                        return NO_WAY;
                                        break;
                                }
                                break;
                        }
                        iMakeTheBestMove = THE_ONLY_MOVE;
                    }
                    return THE_ONLY_MOVE;
                }
                else{
                    aMain[i][j] = ' ';
                    break;
                }
            }
         }
   }
//'3. Check all 7 available Moves

    for (i = 1; i<=7;i++){

        if (Ply > Difficulty){
            if ( WhoWin == 'B'){
                RedCounter[TheMoveCol] = RedCounter[TheMoveCol] - 1;

            }
            else
            {
                RedCounter[TheMoveCol] = RedCounter[TheMoveCol] -10;

                WhoWin = 'B';
            }
            return NO_WAY;
        }
        for (j = 1; j<=6;j++){
            if (aMain[i][j] == ' '){  // 'First avail empty cell in selected column.
                aMain[i][j] = 'R';
                if (Ply == 1){
                    TheMoveCol = i;
                    TheMoveRoW = j;
                }
                Ply = Ply + 1;
                switch ( AssumeHisMove()){
                    case 1:
                        aMain[i][j] = ' ';
                        Ply = Ply - 1;
                        if (WhoWin == 'B'){
                            j=7;
                            break;
                        }
                        else
                        {
                            return NO_WAY;
                        }
                        break;
                    case 2:
                        switch (MakeTheBestMove()){
                            case 1:
                                aMain[i][j] = ' ';
                                Ply = Ply - 1;
                                if (WhoWin == 'B'){
                                    j=7;
                                    break;
                                }
                                else
                                {
                                    return NO_WAY;
                                }
                                break;
                        }
                        break;
                }
            }
        }
    }
    return NO_WAY;
}

//FUNCTION BELOW CAN BE MODIFIED TO COMBINE WITH PREVIOUS, WILL ADD NEXT ITERATION
int AssumeHisMove()
{
    int i;
    int j;
    int k=0;
    int iAssumeHisMove;

//'1. Can He win Immediately?
        for (i = 1; i<=7; i++){
             for (j = 1; j<=6; j++){
                if (aMain[i][j] == ' '){
                    aMain[i][j] = 'B';
                    if (ValidateFour(i, j, 'B')==1){
                        aMain[i][j] = ' ';
                        iAssumeHisMove = NO_WAY;
                        WhoWin = 'B';
                        return iAssumeHisMove;
                    }
                    else{
                        aMain[i][j] = ' ';
                        j=7;
                    }
                }
             }
        }

//2. Does He have to close 3
        for (i = 1; i<=7; i++){
           for (j = 1; j<=6; j++){
               if (aMain[i][j] == ' ') {
                    aMain[i][j] = 'R';
                    if (ValidateFour(i, j, 'R')==1){
                        iAssumeHisMove=THE_ONLY_MOVE;
                        aMain[i][j] = 'B';
                        Ply = Ply + 1;
                        switch (MakeTheBestMove()){
                                case 1:
                                    aMain[i][j] = ' ';
                                    Ply = Ply - 1;
                                    iAssumeHisMove=NO_WAY;
                                    return iAssumeHisMove;
                                    break;
                        }
                    }
                    else{
                        aMain[i][j] = ' ';
                        j=8;

                    }
               }
           }
        }

//3 ' Check all 7 available Moves
            for (i = 1; i<=7;i++){
                for (j = 1; j<=6;j++){
                    if (aMain[i][j] == ' '){  // 'First avail empty cell in selected column.
                        aMain[i][j] = 'B';
                        Ply = Ply + 1;
                        switch ( MakeTheBestMove()){
                            case 1:
                                aMain[i][j] = ' ';
                                Ply = Ply - 1;
                                iAssumeHisMove=NO_WAY;
                                if (WhoWin == 'R'){
                                    j=7;
                                }
                                else
                                {
                                    return NO_WAY;
                                }
                                break;
                        }
                    }
                }
            }

    iAssumeHisMove = NO_WAY;
    for (i = 1;i<=7;i++){
        if (aMain[i][6]!=' '){
            k++;
        }
    }
    if (k==7){
        WhoWin = 'B';
    }
    return iAssumeHisMove;
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
int Obtain(){
    int result=0;
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
            result=(iDifficulty-1)/2+10;

        }
    }while (result==0);
    return result;
}
int main()
{

    int s =0;
    int m =0;
    int i;
    int j;
    int iMax=0;
    CreateHelper();
    Difficulty=ObtainDifficulty();




    for(m=1;m<=7;m++){
        RedCounter[m] = 0;
    }

    for (i = 1; i <= 7; i++){
        for (j = 1; j <= 6; j++){
            aMain[i][j] = ' ';
        }
    }

    aMain[4][1] = 'R';
    displayGrid();
    while(GAME_IS_OVER == 0)
    {
        TheMoveCol = Obtain();

        for(m=1;m<=7;m++){
            RedCounter[m] = 0;
        }
        for (i = 1; i <= 6; i++){
            if (aMain[TheMoveCol][i]==' '){
                 aMain[TheMoveCol][i]='B';
                 break;

            }
        }
        displayGrid();
        if(ValidateFour(TheMoveCol,i,'B')==1){
            printf("Game Over! Player has won!\n");
            GAME_IS_OVER =1;
			//system("pause");
            return 1;

        }
        s = MakeTheBestMove();
        if (WhoWin == 'B')
        {
            for (m=1;m<8;m++)
            {
                if(aMain[m][6]==' ')
                {
                    break;
                }
            }
            if(m==8){
                printf("Game Over! It is a draw\n");
                GAME_IS_OVER=1;
				//system("pause");
                return 1;
            }
            iMax = m;
            for( m = 1;m<8;m++)
            {
                if (RedCounter[m] < RedCounter[iMax])
                {
                    iMax = m;
                }
            }
            TheMoveCol = iMax;

        }
        sColor='R';
        MakeMove (TheMoveCol);
    }
	//system("pause");
    return 0;
}
