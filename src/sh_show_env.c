/*
** main.c for main.c in /home/briand_p/rendu/Semestre_2/System_Unix/echange_42sh/src
** 
** Made by Pierrick Briand
** Login   <briand_p@epitech.net>
** 
** Started on  Tue Mar 31 17:02:49 2015 Pierrick Briand
** Last update Fri May 15 16:41:11 2015 Killian Corbel
*/

#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"

void    show_env(t_main *env)
{
  while (env != NULL)
    {
      printf("%s\n", env->str);
      env = env->next;
    }
}
