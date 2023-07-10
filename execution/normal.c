/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:28:49 by asaber            #+#    #+#             */
/*   Updated: 2023/07/10 23:42:01 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	list_len(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	**convert_list(void)
{
	char	**cp_env;
	char	*tmp_variable;
	t_env	*env;
	int		size;
	int		i;

	env = Glob.env;
	size = list_len(env);
	cp_env = (char **)malloc((size + 1) * sizeof(char *));
	i = 0;
	while (env)
	{
		tmp_variable = ft_strjoin(env->variable, "=");
		cp_env[i] = ft_strjoin(tmp_variable, env->value);
		env = env->next;
		i++;
	}
	cp_env[i] = 0;
	return (cp_env);
}

char	*search_env(char *var)
{
	t_env	*env;
	int		size;

	size = ft_strlen(var);
	env = Glob.env;
	while (env)
	{
		if (!ft_strncmp(var, env->variable, size))
			return (env->value);
		env = env->next;
	}
	return(NULL);
}

// void ifpip(char **command)
// {
// 	//if command has pipe in it then do this
// 	// int		id;
// 	// int		fd[2];
// 	// char	**
// }

int	do_command(char **command)
{
	int		i;
	int		fd;
	char	**paths;
	char	**env;
	int		id;

	paths = ft_split(search_env("PATH"), ':');
	env = convert_list();
	i = 0;
	id = fork();
	if (id == 0)
	{
		fd = open("command.txt", O_RDWR | O_CREAT | O_APPEND, 0777);
		dup2(fd, 1);
		while (paths[i])
		{
			if (execve(command[0], command, env) != -1)
				return (1);
			else if (execve(ft_strjoin(paths[i], ft_strjoin("/", command[0])), command, env) != -1)
				return (1);
			i++;
		}
	}
	else
		waitpid(id, NULL, 0);
	return (0);
}
