/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:44:56 by jchauvet          #+#    #+#             */
/*   Updated: 2023/01/30 10:56:03 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	print_error(char *s1, char *s2, char *s3, char *message)
{
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
	{
		if (s1)
		{
			ft_putstr_fd(": ", 2);
		}
		ft_putstr_fd(s2, 2);
	}
	if (s3)
	{
		if (s1 || s2)
			ft_putstr_fd(": ", 2);
		ft_putstr_fd(message, 2);
	}
	ft_putchar_fd('\n', 2);
	return (ERROR);
}

int	print_error_errno(char *s1, char *s2, char *s3)
{
	print_error(s1, s2, s3, strerror(errno));
	errno = 0;
	return (ERROR);
}
