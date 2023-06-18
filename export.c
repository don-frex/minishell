/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:00:18 by asaber            #+#    #+#             */
/*   Updated: 2023/06/18 21:05:17 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_global(char *str, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (str[i] == '=')
			break ;
		i++;
	}

	if (i <= end)
	{
		_ft_lstadd_back(&Glob.env, _ft_lstnew(cut_first(&str[start]),
				cut_secound(&str[start], cut_first(&str[start]))));
	}
}

void	__export(char **str)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] && (str[i][j] == ' ' || str[i][j] == '\t'))
				j++;
			start = j;
			while (str[i][j] && (str[i][j] != ' ' && str[i][j] != '\t'))
				j++;
			end = j - 1;
			add_global(str[i], start, end);
		}
		i++;
	}
}

