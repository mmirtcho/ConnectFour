#include "connectfour.h"

int ObtainScore(){
  int x, y;
  int score=42;
  for (y = 6; y > 0; y--)
    {
      for (x = 1; x < 8; x++)
        {
	  if(aMain[x][y] == 'R'){
	    score--;
	  }
	  if (aMain[x][y] == 'B'){
	    score--;
	  }
	}
    }
  score=(score*100)/34+1;
  return score;
}
int main()
{
  ObtainScore();
  return 0;
}
