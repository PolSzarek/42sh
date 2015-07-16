/*
** main.c for 42sh in /home/szarek_p/Rendu/Unix/PSU_2014_42sh/src
**
** Made by Pol Szarek
** Login   <pol.szarek@epitech.eu>
**
** Started on  Mon May  4 18:07:13 2015 Pol Szarek
** Last update Fri May 29 17:02:16 2015 Pierrick Briand
*/

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

t_main	*my_env;

void		prompt(t_main *env)
{
  char	*str;

  if ((str = my_getenv(env, "PWD")) != NULL)
    printf("(%s)", str);
  else
    printf("$>");
  fflush(stdout);
  free(str);
}

int		main(int ac, char **av, char **env)
{
  char		*s;

  ac = ac;
  av = av;
  my_env = tab_to_list(env);
  while (42)
    {
      if (signal(SIGINT, sig_handler) == SIG_ERR)
	printf("Error while trying to catch SIGINT.\n");
      prompt(my_env);
      s = get_next_line(0);
      if (s != NULL)
	{
	  if (strlen(s) != 0)
	    parsing(s, 0, &my_env);
	  free(s);
	}
      else	
	break ;
    }
  my_free_list(my_env);
  return (0);
}

void		main_manager(char *s, t_main **my_env)
{
  t_main	*list;
  char		**env;

  env = list_to_tab(*my_env);
  list = NULL;
  parsing_entree(&list, s);
  if (list != NULL)
    {
      if (execution(list, my_env, env) != -1)
	my_free_list(list);
    }
  my_free_tab(env);
}

void	sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("\n");
  prompt(my_env);
}
