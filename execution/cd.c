/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:34:20 by asaber            #+#    #+#             */
/*   Updated: 2023/07/15 20:39:26 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// glob env is a global variable in this case

void	ft_cd(t_pcommand_d *cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (cmd->command[i])
		i++;
	if (i > 2)
	{
		printf("cd: too many arguments\n");
		return ;
	}
	// if is cd with ~ do this
	else if (i == 2 && cmd->command[1][0] == '~')
	{
		tmp = search_env("HOME");
		tmp2 = ft_strjoin(tmp, cmd->command[1] + 1);
		if (chdir(tmp) == -1)
			printf("cd: %s: %s\n", tmp, strerror(errno));
		free(tmp);
		free(tmp2);
	}
	else
	if (i == 1)
	{
		tmp = search_env("HOME");
		if (chdir(tmp) == -1)
			printf("cd: %s: %s\n", tmp, strerror(errno));
		free(tmp);
	}
	else
	{
		if (chdir(cmd->command[1]) == -1)
			printf("cd: %s: %s\n", cmd->command[1], strerror(errno));
	}
	i = 0;
	while (cmd->command[i])
	{
		free(cmd->command[i]);
		i++;
	}
	free(cmd->command);
}
