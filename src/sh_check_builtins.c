/*
** sh_check_builtins.c for 42sh in /home/szarek_p/Rendu/Unix/PSU_2014_42sh/src
**
** Made by Pol Szarek
** Login   <pol.szarek@epitech.eu>
**
** Started on  Mon May  4 18:21:54 2015 Pol Szarek
** Last update Sun May 24 18:28:06 2015 Killian Corbel
*/

#include <string.h>
#include "42sh.h"

int	check_builtins(t_main *list, t_main **env)
{
  if (strcmp(list->str, "cd") == 0)
    my_cd(list, *env);
  else if (strcmp(list->str, "env") == 0)
    show_env(*env);
  else if (strcmp(list->str, "setenv") == 0)
    my_setenv(list, env);
  else if (strcmp(list->str, "unsetenv") == 0)
    my_unsetenv(list, env);
  else if (strcmp(list->str, "exit") == 0)
    my_exit(list);
  else if (strcmp(list->str, "echo") == 0)
    my_echo(list);
  else if (strcmp(list->str, "..") == 0)
    my_cd(manage_double_dots(&list), *env);
  else
    return (0);
  return (1);
}
