/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:03:27 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/03 10:15:51 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	number_of_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_argv_exit(char **argv, t_list *l_free)
{
	if (argv[0] && !argv[1])
	{
		exec_free_all(argv, l_free);
		exit(0);
	}
	if (!ft_is_num(argv[1]) || argv[1][0] == '\0')
	{
		print_error(SHELL_NAME, "exit", argv[1], "numeric argument required");
		exec_free_all(argv, l_free);
		exit(2);
	}
	if (number_of_argv(argv) > 2)
	{
		print_error(SHELL_NAME, "exit", NULL, "too many arguments");
		return (1);
	}
	return (0);
}

int	ft_exit(char **argv, int status, t_list *l_free)
{
	if (isatty(STDERR_FILENO))
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (check_argv_exit(argv, l_free))
		return (1);
	status = ft_atoi(argv[1]);
	exec_free_all(argv, l_free);
	exit(status);
	return (0);
}
