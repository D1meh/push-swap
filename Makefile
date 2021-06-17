CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = main.c \
	  utils/error.c \
	  utils/fill_tab.c \
	  utils/ft_atoi.c \
	  utils/push_swap.c \
	  utils/heapsort.c \
	  utils/is_sort.c \
	  utils/ft_split.c \
	  utils/ft_isdigit.c \
	  utils/utils.c \
	  utils/more_utils.c \
	  utils/toomany_utils.c \
	  listes/ft_lstswap.c \
	  listes/ft_lstsize.c \
	  listes/ft_createlst.c \
	  listes/ft_lstpush.c \
	  listes/ft_lstrotate.c \
	  listes/ft_lst_rrotate.c \
	  listes/new_lstclear.c \
	  listes/ft_lstadd.c \
	  listes/ft_lstclear.c \
	  listes/ft_lstdelone.c \
	  listes/ft_lstlast.c \
	  listes/ft_lstnew.c

OBJ = $(SRC:.c=.o)
RM = rm -f

%.o : %.c 
		$(CC) -o $@ -c $< $(CFLAGS)

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re