/*
** sh_builtins_setenv.c for sh in /home/corbel_k/localwork/echange_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Tue Mar 31 17:29:45 2015 Killian Corbel
** Last update Sun May 24 18:06:13 2015 Killian Corbel
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

char	*gather(char *variable, char *value)
{
  char	*res;
  int	i;

  if ((res = malloc(strlen(variable) + strlen(value) + 2)) == NULL)
    return (NULL);
  i = 0;
  while (i < (int)strlen(value) + (int)strlen(variable) + 1)
    {
      if (i < (int)strlen(variable))
	res[i] = variable[i];
      else if (i > (int)strlen(variable))
	res[i] = value[i - (int)strlen(variable) - 1];
      else
	res[i] = '=';
      i++;
    }
  res[i] = '\0';
  return (res);
}

int	my_setenv(t_main *list, t_main **env)
{
  char	*value;
  char	*variable;

  if (list->next != NULL)
    {
      variable = (list->next)->str;
      if ((list->next)->next != NULL)
	value = ((list->next)->next)->str;
      else
	value = "NULL";
	my_change_env(variable, value, env);
    }
  else
    show_env(*env);
  return (0);
}

int		my_change_env(char *var, char *new_value, t_main **env)
{
  t_main	*elem;
  char		*res;

  elem = *env;
  while (elem != NULL && strncmp(elem->str, var, strlen(var)) != 0)
    elem = elem->next;
  if (elem == NULL)
    {
      if (my_put_in_list(env, gather(var, new_value)) == -1)
	return (-1);
      return (0);
    }
  res = add_equal(var, new_value);
  free(elem->str);
  elem->str = res;
  return (0);
}
