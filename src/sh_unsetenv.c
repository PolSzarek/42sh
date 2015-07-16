/*
** sh_unsetenv.c for unsetenv.c in /home/lepeve_r/blinux/lepeve_r/rendu/PSU/42sh/echange_42sh
** 
** Made by lepeve_r
** Login   <lepeve_r@epitech.net>
** 
** Started on  Wed Apr 22 15:40:14 2015 lepeve_r
** Last update Fri May 15 16:41:29 2015 Killian Corbel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "42sh.h"

int		my_unsetenv(t_main *list, t_main **env)
{
  t_main	*tmp;
  t_main	*del;
  char		*variable;

  tmp = (*env);
  if (list->next != NULL)
    {
      variable = (list->next)->str;
      while (tmp->next != NULL)
	{
	  if (strncmp(variable, tmp->next->str, strlen(variable)) == 0)
	    {
	      del = tmp->next;
	      tmp->next = del->next;
	      free(del);
	      return (0);
	    }
	  tmp = tmp->next;
	}
      printf("%s not found in env.", variable);
      return (-1);
    }
  printf("please enter the line that you want to delete.");
  return (-2);
}
