/*
** my_echo.c for shell in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Sun May 24 18:28:14 2015 Killian Corbel
** Last update Sun May 24 18:35:28 2015 Killian Corbel
*/

#include <stdio.h>
#include <stdlib.h>
#include "42sh.h"

void		my_echo(t_main *list)
{
  t_main	*elem;

  elem = list->next;
  while (elem != NULL)
    {
      printf("%s", elem->str);
      if (elem->next != NULL)
	printf(" ");
      elem = elem->next;
    }
  printf("\n");
}
