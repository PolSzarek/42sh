/*
** path_to_list.c for sh in /home/corbel_k/localwork/PSU_2014_42sh/src
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Wed May 13 19:15:31 2015 Killian Corbel
** Last update Tue May 19 15:46:13 2015 Killian Corbel
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

int	path_to_list(t_main **path, t_main *tab_env)
{
  int	i;
  int	k;
  char	*res;

  if ((res = my_getenv(tab_env, "PATH")) == NULL)
    return (-1);
  i = 0;
  while (res[k = i])
    {
      while (res[k] != ':' && res[k])
	k++;
      my_put_in_list(path, my_selection(res, i, k));
      i = k;
      if (res[k])
  	i++;
    }
  my_put_in_list(path, strdup("."));
  free(res);
  return (0);
}
