/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:09:21 by jchauvet          #+#    #+#             */
/*   Updated: 2023/01/30 10:15:12 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "global.h"
#include "lexer.h"
#include "parser.h"
#include "env.h"

static char	*get_input(void);
static void	process_input(char *input);

char	**g_env = NULL;

int	main(void)
{
	char	*input;

	if (env_init() == ERROR)
		return (EXIT_FAILURE);
	while (1)
	{
		input = get_input();
		if (input == NULL)
		{
			//DO SOMETHING;
		}
		process_input(input);
	}
	rl_clear_history();
	exit(0/*WHATEVER THE LAST EXIT STATUS IS?/WAS?*/); // NOT IMPLEMENTED YET;
}

static char	*get_input(void)
{
	char	*input;
	char	*prompt;

	prompt = env_get_value("PS1");
	if (prompt == NULL)
		prompt = PROMPT;
	if (isatty(STDIN_FILENO))
		input = readline(prompt);
	else
		input = minishell_get_next_line(STDIN_FILENO);
	if (input == NULL)
		return (NULL);
	else if (isatty(STDIN_FILENO) && input && input[0])
		add_history(input);
	return (input);
}

static void	process_input(char *input)
{
	t_list	*l_token;
	t_list	*l_parser;

	//DO SOMETHING;
}
