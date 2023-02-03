/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:23:33 by jchauvet          #+#    #+#             */
/*   Updated: 2023/02/03 14:36:22 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

t_list	*lexer(char *input)
{
	t_list	*tokens;

	tokens = token_list_get(input);
	if (tokens == NULL)
		return (NULL);
	if (lexer_check(tokens) == ERROR)
	{
		//set exit status
		ft_lstclear(&tokens, token_destroy()); //token_destroy TODO
		return (NULL);
	}
	if (env_var_is_value(DEBUG, "print")) // TODO
		print_tokens(tokens); // TODO
	return (tokens);
}
