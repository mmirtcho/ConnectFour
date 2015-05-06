NAME1=connectfour
SRC1=connectfour.c
OBJ1=$(SRC1:.c=.o)
RM=rm -f

all:$(NAME1)

$(NAME1):$(OBJ1)

clean:
        -$(RM) *~
        -$(RM) *.o
        -$(RM) *.core
        -$(RM) *.swp
        -$(RM) \#*

fclean: clean
        -$(RM) $(NAME1)

re: fclean all