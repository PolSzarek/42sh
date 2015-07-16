/*
** gest_semicolon.c for 42sh in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Tue May  5 13:38:35 2015 Killian Corbel
** Last update Fri May 29 17:46:14 2015 Pierrick Briand
*/

#include <stdlib.h>
#include "parsing.h"
#include "42sh.h"

void	gest_semicolon(char *s, int i, int fd_enter, t_main **env)
{
  char	*s1;
  char	*s2;

  if ((s1 = manage_spaces(my_selection(s, 0, i))) == NULL ||
      ((s2 = manage_spaces(s + i + 1)) == NULL))
    exit(-1);  parsing(s1, fd_enter, env);
  parsing(s2, fd_enter, env);
}

int	gest_separators(char *s, int i, int fd_enter, t_main **env)
{
  char	*s1;
  char	*s2;

  s1 = manage_spaces(my_selection(s, 0, i));
  s2 = manage_spaces(s + i + 2);
  parsing(s1, fd_enter, env);
  if (s[i] == '&' && exec_ret == 8)
    return (0);
  else if (s[i] == '|' && exec_ret != 8)
    return (0);
  parsing(s2, fd_enter, env);
  free(s1);
  return (0);
}
