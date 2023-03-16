/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:53:45 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/03 09:51:36 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_unset(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!env_find_var(argv[i]))
			;
		else
			env_unset_var(argv[i]);
		i++;
	}
	return (0);
}
