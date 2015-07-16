##
## Makefile for Makefile in /home/briand_p/rendu/Semestre_2/System_Unix/echange_42sh
##
## Made by Pierrick Briand
## Login   <briand_p@epitech.net>
##
## Started on  Thu Apr 16 19:21:20 2015 Pierrick Briand
## Last update Sun May 24 22:20:37 2015 Killian Corbel
##

NAME	=	42sh

FILES	=	main.c			\
		get_next_line.c		\
		sh_exit.c		\
		cd.c			\
		sh_builtins_setenv.c	\
		sh_list_fonctions.c	\
		sh_show_env.c		\
		sh_parsing_entree.c	\
		sh_str_tools.c		\
		sh_check_builtins.c	\
		sh_unsetenv.c		\
		list_to_tab.c		\
		my_strcat.c		\
		my_execve.c		\
		path_to_list.c		\
		manage_pwds.c		\
		manage_double_dots.c	\
		gest_pipe.c		\
		gest_semicolon.c	\
		is.c			\
		parsing.c		\
		my_echo.c		\
		my_getnbr.c

SRCS	=	$(addprefix ./src/, $(FILES))

OBJ	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-I./include -Wall -Wextra -Werror -W -g

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		clean fclean re
