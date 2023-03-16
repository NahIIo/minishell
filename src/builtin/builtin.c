/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:03:15 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/03 14:42:26 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	builtin_check(char **cmd)
{
	if (cmd[0] && (ft_strcmp(cmd[0], "exit") == 0))
		return (1);
	else if (cmd[0] && (ft_strcmp(cmd[0], "cd") == 0))
		return (1);
	else if (cmd[0] && (ft_strcmp(cmd[0], "pwd") == 0))
		return (1);
	else if (cmd[0] && (ft_strcmp(cmd[0], "env") == 0))
		return (1);
	else if (cmd[0] && (ft_strcmp(cmd[0], "export") == 0))
		return (1);
	else if (cmd[0] && (ft_strcmp(cmd[0], "unset") == 0))
		return (1);
	else if (cmd[0] && (ft_strcmp(cmd[0], "echo") == 0))
		return (1);
	return (0);
}

int	builtin_exec(char **argv, t_list *l_free)
{
	int	status;

	status = 0;
	if (argv[0] && (ft_strcmp(argv[0], "exit") == 0))
		status = ft_exit(argv, status, l_free);
	else if (argv[0] && (ft_strcmp(argv[0], "cd") == 0))
		status = ft_cd(argv);
	else if (argv[0] && (ft_strcmp(argv[0], "pwd") == 0))
		status = ft_pwd();
	else if (argv[0] && (ft_strcmp(argv[0], "env") == 0))
		status = ft_env(argv);
	else if (argv[0] && (ft_strcmp(argv[0], "export") == 0))
		status = ft_export(argv);
	else if (argv[0] && (ft_strcmp(argv[0], "unset") == 0))
		status = ft_unset(argv);
	else if (argv[0] && (ft_strcmp(argv[0], "echo") == 0))
		status = ft_echo(argv);
	return (status);
}
