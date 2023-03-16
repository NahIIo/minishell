/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:42:09 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/03 17:44:23 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <sys/stat.h>

int	ft_pwd(void)
{
	char	*dir;

	dir = env_get_value("PWD");
	if (!dir)
	{
		perror("minishell: pwd: error");
		return (-1);
	}
	printf("%s\n", dir);
	return (0);
}
