/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:44:34 by jchauvet          #+#    #+#             */
/*   Updated: 2023/02/24 09:54:17 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "token.h"

/* FOR DEBUG PURPOSES ONLY */

void	printer_token(t_list *l_token)
{
	printf("\e[37;7mTOKEN:\t\t\e[m");
	if (l_token != NULL)
	{
		while (l_token->next != NULL)
		{
			if (token_content(l_token)->flags & TOK_CONNECTED)
				printf("%s \033[0;35m+ \033[m", token_content(l_token)->str);
			else
				printf("%s \033[0;32m: \033[m", token_content(l_token)->str);
			l_token = l_token->next;
		}
		printf("%s\n", token_content(l_token)->str);
	}
}
