/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:21:06 by asaber            #+#    #+#             */
/*   Updated: 2023/07/19 22:41:11 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// if is heardoc in the command

int	heardoc_check(t_pcommand_d *cmd)
{
	while (cmd)
	{
		if (cmd->file->type == 13)
			return (1);
		cmd = cmd->next;
	}
	return (0);
}
 
// if is heardoc in the command
void	do_heardoc(t_command_d *cmd)
{
	int		id;
	int		fd;
	char	*line;


	id = fork();
	
	if (!id)
	{
		while (1)
		{
			line = readline("> ");
			
		}
		
	}
}