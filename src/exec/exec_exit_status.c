/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:41:55 by jchauvet          #+#    #+#             */
/*   Updated: 2023/02/24 09:35:08 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	*exit_status_pointer(void);

int	exec_exit_status_get(void)
{
	return (*exit_status_pointer());
}

void	exec_exit_status_set(int status)
{
	if (status == ERROR)
		status = EXIT_FAILURE;
	*exit_status_pointer() = status;
}

static int	*exit_status_pointer(void)
{
	static int	last_exit_status = 0;

	return (&last_exit_status);
}
