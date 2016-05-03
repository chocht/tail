##
## Makefile for lib in /home/chauch_p/librairie/lib/my
## 
## Made by Pierre Chauchoy
## Login   <chauch_p@epitech.net>
## 
## Started on  Mon Feb 15 14:15:38 2016 Pierre Chauchoy
## Last update Tue Apr 12 02:22:33 2016 Pierre Chauchoy
##

RM		= rm -f

CP		= cp

LIB_MY		= .

MY		= my

MY_PRINTF	= my_printf

GET_NEXT_LINE	= get_next_line

INC_DIR		= ../../include/

LIB_DIR		= ../

SRCS		= $(LIB_MY)/$(MY)/my_putchar.c \
		  $(LIB_MY)/$(MY)/my_putstr.c \
		  $(LIB_MY)/$(MY)/my_strlen.c \
		  $(LIB_MY)/$(MY)/my_put_nbr.c \
		  $(LIB_MY)/$(MY)/my_putnbr_base.c \
		  $(LIB_MY)/$(MY)/my_getnbr.c \
		  $(LIB_MY)/$(MY)/my_getnbr_base.c \
		  $(LIB_MY)/$(MY)/my_getnbr_float.c \
		  $(LIB_MY)/$(MY)/my_power_rec.c \
		  $(LIB_MY)/$(MY)/my_str_to_wordtab.c \
		  $(LIB_MY)/$(MY)/my_len_wordtab.c \
		  $(LIB_MY)/$(MY)/my_show_wordtab.c \
		  $(LIB_MY)/$(MY)/my_free_wordtab.c \
		  $(LIB_MY)/$(MY)/my_revstr.c \
		  $(LIB_MY)/$(MY)/my_strdup.c \
		  $(LIB_MY)/$(MY)/my_strcpy.c \
		  $(LIB_MY)/$(MY)/my_strncpy.c \
		  $(LIB_MY)/$(MY)/my_strstr.c \
		  $(LIB_MY)/$(MY)/my_strcat_char.c \
		  $(LIB_MY)/$(MY)/my_strcmp.c \
		  $(LIB_MY)/$(MY)/my_strcmp_overflow.c \
		  $(LIB_MY)/$(MY)/my_strncmp.c \
		  $(LIB_MY)/$(MY)/my_strisalpha.c \
		  $(LIB_MY)/$(MY)/my_str_isnum_pos.c \
		  $(LIB_MY)/$(MY)/my_str_isnum.c \
		  $(LIB_MY)/$(MY_PRINTF)/my_printf.c \
		  $(LIB_MY)/$(MY_PRINTF)/my_printf_func_1.c \
		  $(LIB_MY)/$(MY_PRINTF)/my_printf_func_2.c \
		  $(LIB_MY)/$(MY_PRINTF)/my_printf_func_3.c \
		  $(LIB_MY)/$(MY_PRINTF)/my_printf_func_4.c \
		  $(LIB_MY)/$(MY_PRINTF)/my_printf_func_5.c \
		  $(LIB_MY)/$(GET_NEXT_LINE)/get_next_line.c

INC		= $(LIB_MY)/$(MY)/my.h \
		  $(LIB_MY)/$(MY_PRINTF)/my_printf.h \
		  $(LIB_MY)/$(GET_NEXT_LINE)/get_next_line.h

OBJS		= $(SRCS:.c=.o)

NAME		= libmy

LIB		= $(NAME).a

all:		$(NAME)

$(NAME):		$(OBJS)
		ar rc $(LIB) $(OBJS)
		ranlib $(LIB)
		$(CP) $(LIB) $(LIB_DIR)
		$(CP) $(INC) $(INC_DIR)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(LIB)

re: 		fclean all

.PHONY: 	all clean fclean re
