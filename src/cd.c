/*
** cd.c for builtin cd in /home/lepeve_r/blinux/lepeve_r/rendu/PSU/42sh/echange_42sh/cd
** 
** Made by lepeve_r
** Login   <lepeve_r@epitech.net>
** 
** Started on  Tue Mar 31 17:00:48 2015 lepeve_r
** Last update Sat May 23 17:41:31 2015 Killian Corbel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "42sh.h"

int	my_cd(t_main *list, t_main *env)
{
  char	*dest;

  if (list->next == NULL)
    {
      if ((dest = my_getenv(env, "HOME")) == NULL)
	{
	  printf("Error : no home in env\n");
	  return (-1);
	}
    }
  else
    {
      dest = (list->next)->str;
      dest = manage_tild(dest, env);
    }
  if (chdir(dest) == -1)
    printf("Error whith chdir\n");
  else
    if (manage_pwds(dest, &env) == -1)
      printf("Error with PWD changes\n");
  free(dest);
  return (0);
}

char	*manage_tild(char *dest, t_main *env)
{
  if (dest[0] == '-' && dest[1] == 0)
    {
      if ((dest = my_getenv(env, "OLDPWD")) == NULL)
	{
	  printf("Error : no OLDPWD in env\n");
	  dest = strdup(".");
	}
    }
  else if (dest[0] == '~')
    {
      dest = replace_tild(dest, env);
    }
  else
    dest = strdup(dest);
  return (dest);
}

char	*replace_tild(char *dest, t_main *env)
{
  char	*home;
  char	*res;

  if ((home = my_getenv(env, "HOME")) == NULL)
    {
      printf("Error : no home in env\n");
      return (strdup("."));
    }
  if ((res = malloc(strlen(home) + strlen(dest))) == NULL)
    {
      printf("Error : malloc\n");
      return (strdup("."));
    }
  res = concatenate(res, home, dest);
  free(home);
  return (res);
}

char	*concatenate(char *res, char *home, char *dest)
{
  int	i;
  int	len;
  int	len2;

  len = strlen(home);
  len2 = strlen(dest);
  i = 0;
  while (i < len + len2 - 1)
    {
      if (i < len)
	res[i] = home[i];
      else
	res[i] = dest[i - len + 1];
      i++;
    }
  res[i] = '\0';
  return (res);
}
