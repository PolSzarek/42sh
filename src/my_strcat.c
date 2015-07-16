/*
** my_strcat.c for strcat in /media/lepeve_r/2337a639-4d85-4f36-ade6-cdcedffd0cf2/lepeve_r/rendu/PSU/42sh/PSU_2014_42sh/src
** 
** Made by lepeve_r
** Login   <lepeve_r@epitech.net>
** 
** Started on  Tue May  5 17:20:52 2015 lepeve_r
** Last update Tue May  5 17:26:29 2015 Pierrick Briand
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char    *my_strcat(char *dest, char *cmd)
{
  int   i;
  int   j;
  int   x;
  int   a;
  char  *res;

  i = strlen(dest);
  j = strlen(cmd);
  x = 0;
  a = 0;
  if ((res = malloc(sizeof(char) * ((i + j) + 1))) == NULL)
    return (NULL);
  while (dest[x] != '\0')
    {
      res[x] = dest[x];
      x++;
    }
  res[x] = '/';
  x++;
  while (cmd[a] != '\0')
    res[x++] = cmd[a++];
  res[x] = '\0';
  return (res);
}
