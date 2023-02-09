/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:41:08 by jchauvet          #+#    #+#             */
/*   Updated: 2023/02/09 09:41:11 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"

int	builtin_unset(int argc __attribute((unused)), char **argv)
{
	int	status;
	int	i;
	int	j;

	status = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && env_is_var_char(argv[i][j]))
			j++;
		if (argv[i][j] == '\0' || argv[i][0] != '\0')
			env_unset_var(argv[i]);
		i++;
	}
	return (status);
}
