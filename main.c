/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:22:41 by asaber            #+#    #+#             */
/*   Updated: 2023/06/18 21:02:11 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	Glob.env = __fill_env(env);
	if (ft_strncmp(av[1], "pwd", 3) == 0)
		__pwd(Glob.env);
	if (ft_strncmp(av[1], "env", 3) == 0)
		__env(Glob.env);
	if (ft_strncmp(av[1], "export", 3) == 0)
	{
		__export(av);
		__env(Glob.env);
	}
	return (0);
}
