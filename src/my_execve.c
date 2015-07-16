/*
** execve.c for execve in /home/drack_q/42sh/echange_42sh/git_branch
** 
** Made by Quentin Drack
** Login   <drack_q@epitech.net>
** 
** Started on  Tue Mar 31 16:49:05 2015 Quentin Drack
** Last update Fri May 29 16:53:11 2015 Pierrick Briand
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "42sh.h"

int		execution(t_main *list, t_main **my_env, char **env)
{
  int		ret;
  t_main	*path;
  char		**tab;

  path = NULL;
  if (path_to_list(&path, *my_env) == -1)
    {
      printf("Error with mallocs or no path\n");
      return (-1);
    }
  ret = check_builtins(list, my_env);
  if (ret == 0)
    {
      tab = list_to_tab(list);
      my_execve(path, tab, env);
      my_free_tab(tab);
    }
  else if (ret == -1)
    return (-1);
  my_free_list(path);
  return (0);
}

int	my_execve(t_main *path, char **tab, char **env)
{
  pid_t	pid;
  int	status;

  pid = fork();
  if (pid == -1)    
    printf("Error with fork\n");
  if (pid == 0)
    do_the_exec(path, tab, env);
  else
    {
      wait(&status);
      if ((exec_ret = WEXITSTATUS(status)) == 8)
	printf("Command not found\n");
    }
  return (0);
}

int		do_the_exec(t_main *path, char **tab, char **env)
{
  t_main	*elem;
  char		*temp;

  elem = path;
  if (path != NULL)
    {
      while (elem != NULL)
	{
	  temp = add_slash(elem->str, tab[0]);
	  execve(temp, tab, env);
	  elem = elem->next;
	  free(temp);
	}
    }
  execve(tab[0], tab, env);
  exit(8);
}

char	*add_equal(char *path, char *cmd)
{
  char	*res;
  int	i;
  int	len;
  int	len2;

  len = strlen(path);
  len2 = strlen(cmd);
  i = 0;
  if ((res = malloc(len + len2 + 2)) == NULL)
    return (NULL);
  while (i < len + len2 + 1)
    {
      if (i < len)
	res[i] = path[i];
      else if (i == len)
	res[i] = '=';
      else
	res[i] = cmd[i - len - 1];
      i++;
    }
  res[i] = '\0';
  return (res);
}

char	*add_slash(char *path, char *cmd)
{
  char	*res;
  int	i;
  int	len;
  int	len2;

  len = strlen(path);
  len2 = strlen(cmd);
  i = 0;
  if ((res = malloc(len + len2 + 2)) == NULL)
    return (NULL);
  while (i < len + len2 + 1)
    {
      if (i < len)
	res[i] = path[i];
      else if (i == len)
	res[i] = '/';
      else
	res[i] = cmd[i - len - 1];
      i++;
    }
  res[i] = '\0';
  return (res);
}
