/*
** my_exit.c for 42sh in /home/szarek_p/Rendu/Unix/echange_42sh
**
** Made by Pol Szarek
** Login   <pol.szarek@epitech.eu>
**
** Started on  Tue Mar 31 17:03:36 2015 Pol Szarek
** Last update Sun May 24 21:59:57 2015 Pol Szarek
*/

#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"

void     my_exit(t_main *main)
{
  int ret;

  if (main->next == NULL)
    {
      my_free_list(main);
      exit(0);
    }
  else
    {
      ret = my_getnbr((main->next)->str);
      my_free_list(main);
      exit (ret);
    }
}
