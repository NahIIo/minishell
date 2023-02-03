/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 08:09:21 by jchauvet          #+#    #+#             */
/*   Updated: 2023/02/02 11:16:49 by jchauvet         ###   ########.fr       */
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
#include "signals.h"

static char	*get_input(void);
static void	process_input(char *input);

char	**g_env = NULL;

int	main(void)
{
	char	*input;

	signal(SIGQUIT, SIG_IGN);
	if (env_init() == ERROR)
		return (EXIT_FAILURE);
	while (1)
	{
		signal(SIGINT, signal_ctlc);
		input = get_input();
		if (input == NULL)
		{
			/*DO SOMETHING*/;
		}
		process_input(input);
	}
	rl_clear_history();
	if (g_env)
		ft_free_split(&g_env);
	exit(0/*WHATEVER THE LAST EXIT STATUS IS?/WAS?*/); /* NOT IMPLEMENTED YET */;
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

	l_token = NULL;
	l_parser = NULL;
	l_token = lexer(input); /* TODO */
	if (l_token != NULL)
		l_parser = parser(l_token); /* TODO */
	/* EXEC LIST OF CMD?*/
}
