/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:26:02 by asaber            #+#    #+#             */
/*   Updated: 2023/06/18 21:02:21 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct env
{
	char		*variable;
	char		*value;
	struct env	*next;
}	t_env;

typedef struct s_shell
{
	t_env	*env;
}	t_shell;

void	_ft_lstadd_back(t_env **lst, t_env *new);
char	*cut_first(char *env);
char	*cut_secound(char *env, char *first_env);
t_env	*_ft_lstnew(void *variable, void *value);
size_t	ft_strlen(const char *c);
t_env	*__fill_env(char **env);
void	__export(char **str);
void	__pwd(t_env *env);
void	__env(t_env *env);

t_shell		Glob;
#endif