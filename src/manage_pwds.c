/*
** manage_pwds.c for sh in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Fri May 15 17:02:49 2015 Killian Corbel
** Last update Sun May 24 18:11:15 2015 Killian Corbel
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

int	manage_pwds(char *dest, t_main **env)
{
  if (dest[strlen(dest) - 1] == '/')
    dest[strlen(dest) - 1] = 0;
  if (strcmp(dest, ".") == 0)
    return (0);
  if (dest[0] == '/')
    {
      if (replace_pwds(dest, env) == -1)
	return (-1);
    }
  else if (strcmp(dest, "..") == 0)
    {
      if (suppr_last_pwd(env) == -1)
	return (-1);
    }
  else
    if (add_pwd(dest, env) == -1)
      return (-1);
  return (0);
}

int	replace_pwds(char *dest, t_main **env)
{
  char	*temp;

  temp = my_getenv(*env, "PWD");
  if (my_change_env("OLDPWD", temp, env) == -1)
    return (-1);
  if (my_change_env("PWD", dest, env) == -1)
    return (-1);
  free(temp);
  return (0);
}

int	add_pwd(char *dest, t_main **env)
{
  char	*temp;
  char	*new_pwd;

  if ((temp = my_getenv(*env, "PWD")) == NULL)
    return (-1);
  if (temp[strlen(temp) - 1] == '/')
    temp[strlen(temp) - 1] = 0;
  new_pwd = add_slash(temp, dest);
  if (my_change_env("PWD", new_pwd, env) == -1)
    return (-1);
  if (my_change_env("OLDPWD", temp, env) == -1)
    return (-1);
  free(temp);
  free(new_pwd);
  return (0);
}

int	last_slash(char *str)
{
  int	k;
  int	i;

  i = 0;
  k = 0;
  while (str[i])
    {
      if (str[i] == '/')
	k = i;
      i++;
    }
  return (k);
}

int    	suppr_last_pwd(t_main **env)
{
  char	*pwd;
  int	k;
  char	*res;

  k = 0;
  if ((pwd = my_getenv(*env, "PWD")) == NULL)
    return (-1);
  if (strcmp(pwd, "/") == 0)
    return (0);
  k = last_slash(pwd);
  if (k != 0)
    res = my_selection(pwd, 0, k);
  else
    res = strdup("/");
  if (my_change_env("PWD", res, env) == -1 ||
      my_change_env("OLDPWD", pwd, env) == -1)
    return (-1);
  free(pwd);
  free(res);
  return (0);
}
