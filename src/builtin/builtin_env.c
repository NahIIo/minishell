/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:32 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/02 19:27:12 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_env(char **argv)
{
	int	i;

	i = 0;
	if (!argv[1])
	{
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
