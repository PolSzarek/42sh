/*
** parsing.h for sh in /home/corbel_k/localwork/PSU_2014_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Wed May 13 18:35:05 2015 Killian Corbel
** Last update Sun May 24 20:05:13 2015 Pierrick Briand
*/

#ifndef PARSING_H_
#define PARSING_H_

#include "42sh.h"

void	parsing(char *s, int fd_enter, t_main **env);
void	gest_semicolon(char *s, int i, int fd_enter, t_main **env);
void	gest_pipe(char *s, int i, int fd_enter, t_main **env);
void	manage_son(int fd_enter, int fd_sortie, char *s1, t_main **env);
void	manage_father(int fd_enter, char *s2, t_main **env);
char	*manage_spaces(char *s);
int	is_semicolon(char *s);
int	is_pipe(char *s);
int     separate_and(char *s);
int     separate_or(char *s);
int     gest_separators(char *s, int i, int fd_enter, t_main **env);

#define BUFFER_SIZE 1024

#endif
