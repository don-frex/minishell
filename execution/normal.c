/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:28:49 by asaber            #+#    #+#             */
/*   Updated: 2023/07/13 01:18:57 by asaber           ###   ########.fr       */
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

char *check_command(char **path, char *command)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], ft_strjoin("/", command));
		if (access(tmp, F_OK) == 0)
			return (tmp);
		i++;
	}
	return (NULL);
}

// void	if_file(t_command_d *cmd)
// {
// 	int	fd;
	
// }

int	do_command(t_pcommand_d *cmd)
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
		// while (cmd)
		// {
		// 	if (cmd->file)
		// 	{
		// 		while (cmd->file->next)
		// 		{
		// 			if (cmd->file->type == 8)
		// 				fd = open(cmd->file->file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
		// 			else if (cmd->file->type == 14)
		// 				fd = open(cmd->file->file_name, O_RDONLY);
		// 			if (fd == -1)
		// 			{
		// 				printf("minishell: %s: %s\n", cmd->file->file_name, strerror(errno));
		// 				return (1);
		// 			}
		// 			dup2(fd, 1);
		// 			cmd->file = cmd->file->next;
		// 		}
		// 	}
		printf("command: %s\n", cmd->command[0]);
		if ((fd = redirection(cmd)) != -1)
		{
			if (check_command(paths, cmd->command[0]))
				execve(check_command(paths, cmd->command[0]), cmd->command, env);
			else
				printf("minishell>: %s: command not found\n", cmd->command[0]);
				cmd = cmd->next;
		}
		else
			exit(EXIT_FAILURE);
		// }
	}
	else
		wait(NULL);
	return (0);
}
