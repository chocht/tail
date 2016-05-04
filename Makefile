##
## Makefile for tail in /home/chauch_p/Repositories/tail
## 
## Made by Pierre Chauchoy
## Login   <chauch_p@epitech.net>
## 
## Started on  Tue May  3 10:18:50 2016 Pierre Chauchoy
## Last update Wed May  4 08:58:20 2016 Pierre Chauchoy
##

CC		= gcc

RM		= rm -f

NAME		= tail

DIR		= srcs

SRCS		= $(DIR)/main.c \
		  $(DIR)/list_swap.c \
		  $(DIR)/parsing.c \
		  $(DIR)/my_tail.c \
		  $(DIR)/display.c \
		  $(DIR)/display2.c \
		  $(DIR)/args_simple.c \
		  $(DIR)/args_short.c \
		  $(DIR)/args_long.c \
		  $(DIR)/list.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -I./include/
CFLAGS		+= -lmy -L./lib/
CFLAGS		+= -W -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
