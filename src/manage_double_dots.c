/*
** manage_double_dots.c for 42sh in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Sat May 23 10:48:29 2015 Killian Corbel
** Last update Sat May 23 10:52:18 2015 Killian Corbel
*/

#include <string.h>
#include "42sh.h"

t_main	*manage_double_dots(t_main **list)
{
  if ((*list)->next == NULL)
    my_put_in_list(list, strdup(".."));
  else
    ((*list)->next)->str = strdup("..");
  return (*list);
}
