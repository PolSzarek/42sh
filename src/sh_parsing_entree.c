/*
** sh_parsing_entree.c for sh in /home/corbel_k/localwork/echange_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Tue Mar 31 16:50:37 2015 Killian Corbel
** Last update Fri May 15 16:40:54 2015 Killian Corbel
*/

#include "42sh.h"

int	parsing_entree(t_main **list, char *str)
{
  int	i;
  int	k;

  i = 0;
  while (str[i])
    {
      while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	i++;
      k = i;
      while (str[k] != ' ' && str[k] != '\t' && str[k] != '\0')
	k++;
      if (k != i)
	{
	  if (my_put_in_list(list, my_selection(str, i, k)) == -1)
	    return (-1);
	}
      i = k;
    }
  return (0);
}
