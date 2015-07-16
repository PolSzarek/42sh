/*
** 42sh.h for sh in /home/corbel_k/localwork/echange_42sh
** 
** Made by Killian Corbel
** Login   <corbel_k@epitech.net>
** 
** Started on  Wed Apr 22 14:41:02 2015 Killian Corbel
** Last update Sun May 24 22:00:33 2015 Pol Szarek
*/

#ifndef _42SH_H_
# define _42SH_H_

typedef struct	s_main {
  char		*str;
  struct s_main	*next;
}		t_main;

int     exec_ret;

int	my_cd(t_main *list, t_main *env);
char	*manage_tild(char *dest, t_main *env);
char	*replace_tild(char *dest, t_main *env);
char	*concatenate(char *res, char *home, char *dest);
char	*get_next_line(const int fd);
char	**list_to_tab(t_main *list);
int	execution(t_main *list, t_main **my_env, char **env);
int	my_execve(t_main *path, char **tab, char **env);
int	do_the_exec(t_main *path, char **tab, char **env);
char	*add_slash(char *path, char *cmd);
int	path_to_list(t_main **path, t_main *tab_env);
char	*gather(char *variable, char *value);
int	my_setenv(t_main *list, t_main **env);
int	check_builtins(t_main *list, t_main **env);
void    my_exit(t_main *main);
int	my_put_in_list(t_main **list, char *str);
t_main	*my_get_last(t_main **list);
void	my_free_list(t_main *list);
int	parsing_entree(t_main **list, char *str);
void    show_env(t_main *env);
char	*my_selection(char *str, int i, int j);
t_main	*tab_to_list(char **tab);
int	my_unsetenv(t_main *list, t_main **env);
void	my_free_tab(char **tab);
char	*my_getenv(t_main *env, char *variable);
int	manage_pwds(char *dest, t_main **env);
int	replace_pwds(char *dest, t_main **env);
char	*add_equal(char *path, char *cmd);
int	my_change_env(char *var, char *new_value, t_main **env);
int	add_pwd(char *dest, t_main **env);
int    	suppr_last_pwd(t_main **env);
t_main	*manage_double_dots(t_main **list);
void	parsing(char *s, int fd_enter, t_main **env);
void	main_manager(char *s, t_main **my_env);
void	my_echo(t_main *list);
void	sig_handler(int signo);
int	my_getnbr(char *str);

#endif
