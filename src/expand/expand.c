/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:36:18 by jchauvet          #+#    #+#             */
/*   Updated: 2023/03/14 08:52:09 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "env.h"

int	expand_var(t_c_scmd *c_scmd)
{
	int		status;

	status = expand_var_token_list(c_scmd->l_argv);
	if (status != ERROR)
		status = expand_var_token_list(c_scmd->l_redir);
	if (status != ERROR)
		status = expand_var_splitting(&(c_scmd->l_argv));
	if (status != ERROR)
		status = expand_var_splitting(&(c_scmd->l_redir));
	return (status);
}

int	expand_wildcard(t_c_scmd *c_scmd)
{
	char	**files;
	int		status;

	files = expand_files_current_dir();
	if (files == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	status = expand_wildcard_list(&(c_scmd->l_argv), files);
	if (status != ERROR)
		status = expand_wildcard_list(&(c_scmd->l_redir), files);
	ft_free_split(&files);
	return (status);
}

int	check_token(t_c_token *c_token, int *i)
{
	if (c_token->str[*i] == '$' && (env_is_var_char(c_token->str[*i + 1])
			|| (c_token->str[*i + 1] == '\0'
				&& !(c_token->flags & (TOK_S_QUOTE | TOK_D_QUOTE))
				&& c_token->flags & TOK_CONNECTED)))
		return (1);
	return (0);
}
