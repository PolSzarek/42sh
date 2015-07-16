/*
** is.c for sh in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Wed May 13 18:31:57 2015 Killian Corbel
** Last update Fri May 29 17:46:17 2015 Pierrick Briand
*/

#include <stdlib.h>
#include <string.h>

char	*manage_spaces(char *str)
{
  int	len;
  char	*result;

  len = strlen(str) - 1;
  while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
    len--;
  len++;
  str[len] = '\0';
  len = 0;
  while (str[len] == ' ' || str[len] == '\t')
    len++;
  result = strdup(&str[len]);
  return (result);
}

int	is_semicolon(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == ';')
	return (i);
      i++;
    }
  return (0);
}

int	is_pipe(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '|')
	return (i);
      i++;
    }
  return (0);
}

int	separate_and(char *s)
{
  int	i;

  i = 0;
  while (s[i + 1])
    {
      if (s[i] == '&' && s[i + 1] == '&')
	return (i);
      i++;
    }
  return (0);
}

int	separate_or(char *s)
{
  int	i;

  i = 0;
  while (s[i + 1])
    {
      if (s[i] == '|' && s[i + 1] == '|')
	return (i);
      i++;
    }
  return (0);
}
