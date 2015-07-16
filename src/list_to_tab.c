/*
** list_to_tab.c for list_to_tab in /media/lepeve_r/2337a639-4d85-4f36-ade6-cdcedffd0cf2/lepeve_r/rendu/PSU/42sh/PSU_2014_42sh/src
** 
** Made by lepeve_r
** Login   <lepeve_r@epitech.net>
** 
** Started on  Tue May  5 17:00:13 2015 lepeve_r
** Last update Fri May 29 16:59:58 2015 Pierrick Briand
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "42sh.h"

int	my_listlen(t_main *list)
{
  int	nb_elem;

  if (list == NULL)
    return (0);
  nb_elem = 1;
  while (list != NULL)
    {
      list = list->next;
      nb_elem++;
    }
  return (nb_elem);
}

char	**list_to_tab(t_main *list)
{
  char		**tab;
  int		y;

  y = 0;
  if ((tab = malloc(sizeof(*tab) * (my_listlen(list)) + 1)) == NULL)
    return (NULL);
  while (list != NULL)
    {
      tab[y] = strdup(list->str);
      list = list->next;
      y++;
    }
  tab[y] = NULL;
  return (tab);
}

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  tab[i] = NULL;
	  i++;
	}
      free(tab);
    }
}
