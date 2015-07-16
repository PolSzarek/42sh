/*
** gest_pipe.c for 42sh in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Tue May  5 14:27:58 2015 Killian Corbel
** Last update Fri May 29 17:43:12 2015 Pierrick Briand
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "parsing.h"

void	gest_pipe(char *s, int i, int fd_enter, t_main **env)
{
  char	*s1;
  char	*s2;
  pid_t	pid;
  int	pipefd[2];

  if ((s1 = manage_spaces(my_selection(s, 0, i))) == NULL ||
      ((s2 = manage_spaces(s + i + 1)) == NULL))
    exit(-1);
  if ((pipe(pipefd) != -1) && ((pid = fork()) != -1))
    {
      if (pid == 0)
	{
	  close(pipefd[0]);
	  manage_son(fd_enter, pipefd[1], s1, env);
	}
      else
	{
	  close(pipefd[1]);
	  wait(NULL);
	  manage_father(pipefd[0], s2, env);
	}
    }
  free(s1);
}

void	manage_son(int fd_enter, int fd_sortie, char *s1, t_main **env)
{
  int	save_stdin;
  int	save_stdout;

  save_stdout = dup(1);
  save_stdin = dup(0);
  dup2(fd_sortie, 1);
  dup2(fd_enter, 0);
  parsing(s1, fd_sortie, env);
  dup2(save_stdin, 0);
  dup2(save_stdout, 1);
  close(save_stdin);
  close(save_stdout);
  close(fd_sortie);
  close(fd_enter);
  exit(0);
}

void	manage_father(int fd_enter, char *s2, t_main **env)
{
  int	save_stdin;

  save_stdin = dup(0);
  dup2(fd_enter, 0);
  parsing(s2, fd_enter, env);
  dup2(save_stdin, 0);
  close(fd_enter);
  close(save_stdin);
}
