/*
** sh_str_tools.c for sh in /home/corbel_k/localwork/echange_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Tue Mar 31 17:15:36 2015 Killian Corbel
** Last update Sun May 24 17:47:40 2015 Killian Corbel
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

char	*my_selection(char *str, int i, int j)
{
  char	*res;
  int	k;

  if ((res = malloc(j - i + 1)) == NULL)
    return (NULL);
  k = 0;
  while (i != j)
    {
      res[k] = str[i];
      i++;
      k++;
    }
  res[k] = '\0';
  return (res);
}

t_main		*tab_to_list(char **tab)
{
  t_main	*env;
  int		i;

  env = NULL;
  i = 0;
  while (tab[i])
    {
      my_put_in_list(&env, strdup(tab[i]));
      i++;
    }
  return (env);
}

char		*my_getenv(t_main *env, char *variable)
{
  t_main	*elem;

  elem = env;
  while (elem != NULL && strncmp(elem->str, variable, strlen(variable)) != 0)
    elem = elem->next;
  if (elem == NULL)
    return (NULL);
  return (my_selection(elem->str, strlen(variable) + 1, strlen(elem->str)));
}
