/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:39:54 by jchauvet          #+#    #+#             */
/*   Updated: 2023/02/24 09:39:00 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include "cmd.h"
# include "token.h"

t_list	*parser(t_list *l_token);
int		parser_heredoc(t_list *l_token);
int		parser_cmd_pipeline_merge(t_list **l_cmd);
t_list	*parser_scmd_tokens(t_list *l_token);

#endif
