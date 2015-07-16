/*
** get_next_line.c for get_next_line in /home/lepeve_r/blinux/lepeve_r/Rendu/projet_en_cours/get_next_line
**
** Made by lepeve_r
** Login   <lepeve_r@epitech.net>
**
** Started on  Wed Nov 19 10:56:55 2014 lepeve_r
** Last update Mon Feb  9 16:04:55 2015 lepeve_r
*/

#include <stdlib.h>
#include <unistd.h>
# define BUFFER_SIZE (100)

int	my_strlen(char *str)
{
  int	cpt;

  cpt = 0;
  if (str == NULL)
    return (0);
  while (str[cpt] != '\0')
    cpt++;
  return (cpt);
}

char	*my_nremalloc(char *dest, char *src, int n)
{
  int	size_dest;
  char	*res;
  int	cpt;
  int	cpt2;

  cpt = 0;
  cpt2 = 0;
  size_dest = my_strlen(dest) + n;
  if ((res = malloc(sizeof(char) * (size_dest + 1))) == NULL)
    return (NULL);
  while (dest != NULL && dest[cpt] != '\0')
    res[cpt2++] = dest[cpt++];
  cpt = 0;
  while (src != NULL && src[cpt] != '\0' && cpt < n)
    res[cpt2++] = src[cpt++];
  res[cpt2] = '\0';
  free(dest);
  return (res);
}

char	*checkbuff(char *buff, int *av, char *res)
{
  int	i;

  if ((*av == 0 && buff[*av] == '\0') || buff[*av] == '\0')
    {
      *av = 0;
      return (NULL);
    }
  i = *av;
  while (buff[i] != '\0' && buff[i] != '\n')
    i++;
  if ((res = my_nremalloc(res, &buff[*av], i - *av)) == NULL)
    return (NULL);
  *av = i;
  if (buff[*av] == '\0')
    *av = 0;
  else
    (*av)++;
  return (res);
}

char	*get_next_line(const int fd)
{
  char	*res;
  static  char	buff[BUFFER_SIZE + 1];
  static  int	av;
  int	counter;

  res = checkbuff(buff, &av, NULL);
  if (av != 0)
    return (res);
  while ((counter = read(fd, buff, BUFFER_SIZE)) != -1)
    {
      buff[counter] = '\0';
      if (counter == 0)
	return (res);
      av = 0;
      res = checkbuff(buff, &av, res);
      if (av != 0)
	return (res);
    }
  return (NULL);
}
