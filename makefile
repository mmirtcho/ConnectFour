NAME1=connectfour
NAME2=ObtainInstructionsTest
NAME3=PrintHighScoreTest
NAME4=DisplayGridTest
NAME5=ObtainNameTest
NAME6=ObtainDifficultyTest
NAME7=ObtainMoveTest
NAME8=MakeMoveTest
NAME9=ObtainScoreTest
NAME10=SortInstructionsTest
NAME11=ValidateFourTest
SRC1=connectfour.c
SRC2=ObtainInstructionsTest.c
SRC3=PrintHighScoreTest.c
SRC4=DisplayGridTest.c
SRC5=ObtainNameTest.c
SRC6=ObtainDifficultyTest.c
SRC7=ObtainMoveTest.c
SRC8=MakeMoveTest.c
SRC9=ObtainScoreTest.c
SRC10=SortInstructionsTest.c
SRC11=ValidateFourTest.c
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.c=.o)
OBJ3=$(SRC3:.c=.o)
OBJ4=$(SRC4:.c=.o)
OBJ5=$(SRC5:.c=.o)
OBJ6=$(SRC6:.c=.o)
OBJ7=$(SRC7:.c=.o)
OBJ8=$(SRC8:.c=.o)
OBJ9=$(SRC9:.c=.o)
OBJ10=$(SRC10:.c=.o)
OBJ11=$(SRC11:.c=.o)
RM=rm -f

all:$(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5) $(NAME6) $(NAME7) $(NAME8) $(NAME9) $(NAME10) $(NAME11)

$(NAME1):$(OBJ1)

$(NAME2):$(OBJ2)

$(NAME3):$(OBJ3)

$(NAME4):$(OBJ4)

$(NAME5):$(OBJ5)

$(NAME6):$(OBJ6)

$(NAME7):$(OBJ7)

$(NAME8):$(OBJ8)

$(NAME9):$(OBJ9)

$(NAME10):$(OBJ10)

$(NAME11):$(OBJ11)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean: clean
	-$(RM) $(NAME1)
	-$(RM) $(NAME2)
	-$(RM) $(NAME3)
	-$(RM) $(NAME4)
	-$(RM) $(NAME5)
	-$(RM) $(NAME6)
	-$(RM) $(NAME7)
	-$(RM) $(NAME8)
	-$(RM) $(NAME9)
	-$(RM) $(NAME10)
	-$(RM) $(NAME11)

re: fclean all	

