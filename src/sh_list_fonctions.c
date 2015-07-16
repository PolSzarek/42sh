/*
** sh_list_fonctions.c for sh in /home/corbel_k/localwork/echange_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Tue Mar 31 17:03:26 2015 Killian Corbel
** Last update Fri May 15 16:40:43 2015 Killian Corbel
*/

#include <stdlib.h>
#include "42sh.h"

int		my_put_in_list(t_main **list, char *str)
{
  t_main	*elem;

  if (str == NULL)
    return (-1);
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->str = str;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      (my_get_last(list))->next = elem;
    }
  return (0);
}

t_main		*my_get_last(t_main **list)
{
  t_main	*elem;

  elem = *list;
  while (elem->next != NULL)
    elem = elem->next;
  return (elem);
}

void		my_free_list(t_main *list)
{
  t_main	*elem;
  t_main	*elem2;

  if (list != NULL)
    {
      elem = list;
      while (elem != NULL)
	{
	  elem2 = elem;
	  elem = elem->next;
	  free(elem2->str);
	  elem2->str = NULL;
	  free(elem2);
	}
    }
}
