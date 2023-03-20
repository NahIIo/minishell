/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:32 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/20 09:41:25 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_env(char **argv)
{
	int	i;

	i = 0;
	if (!argv[1])
	{
		if (g_env && g_env[i])
			while (g_env[i])
			{
				printf("%s\n", g_env[i]);
				i++;
			}
	}
	else
		return (print_error(SHELL_NAME, argv[0], NULL, "Too many arguments"));
	return (0);
}
