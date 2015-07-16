/*
** my_getnbr.c for 42sh in /home/szarek_p/Rendu/Unix/PSU_2014_42sh/src
**
** Made by Pol Szarek
** Login   <pol.szarek@epitech.eu>
**
** Started on  Sun May 24 21:29:36 2015 Pol Szarek
** Last update Sun May 24 21:58:45 2015 Pol Szarek
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	pow;

  nb = 0;
  i = 0;
  pow = 1;
  if (str[0] == '-')
    i++;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  i--;
  while (i >= 1 && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb + (pow * (str[i] - '0'));
      pow = pow * 10;
      i = i - 1;
    }
  if (str[0] == '-')
    nb = nb * (-1);
  else if (str[i] >= '0' && str[i] <= '9')
    nb = nb + (pow * (str[0] - '0'));
  return (nb);
}
