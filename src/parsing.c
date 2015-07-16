/*
** main.c for 42sh in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Mon May  4 22:11:00 2015 Killian Corbel
** Last update Fri May 29 16:41:56 2015 Pierrick Briand
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parsing.h"
#include "42sh.h"

void	parsing(char *s, int fd_enter, t_main **env)
{
  int	i;

  if ((i = separate_and(s)))
    gest_separators(s, i, fd_enter, env);
  else if ((i = separate_or(s)))
    gest_separators(s, i, fd_enter, env);
  else if ((i = is_semicolon(s)))
    gest_semicolon(s, i, fd_enter, env);
  else if ((i = is_pipe(s)))
    gest_pipe(s, i, fd_enter, env);
  else
    main_manager(s, env);
}
