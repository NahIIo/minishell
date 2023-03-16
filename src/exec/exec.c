/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:41:55 by jchauvet          #+#    #+#             */
/*   Updated: 2023/03/03 17:34:18 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>

#include "exec.h"
#include "cmd.h"

int	exec_recursive(t_list *l_cmd, t_list *l_free)
{
	if (cmd_type(l_cmd) == CMD_SCMD)
		exec_exit_status_set(exec_scmd(l_cmd, l_free));
	else if (cmd_type(l_cmd) == CMD_PIPELINE)
		exec_exit_status_set(exec_pipeline(l_cmd, l_free));
	if (l_cmd->next)
	{
		l_cmd = l_cmd->next;
		if (l_cmd != NULL)
			exec_exit_status_set(exec_recursive(l_cmd->next, l_free));
	}
	return (exec_exit_status_get());
}

void	exec_free_all(char **argv, t_list *l_free)
{
	if (argv)
		ft_free_split(&argv);
	if (l_free)
		ft_lstclear(&l_free, c_cmd_destroy);
	if (g_env)
		ft_free_split(&g_env);
	rl_clear_history();
}
