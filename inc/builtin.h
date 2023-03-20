/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:46:27 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/20 09:08:30 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <readline/readline.h>

# include "cmd.h"
# include "exec.h"
# include "global.h"
# include "env.h"

int		builtin_check(char **cmd);
int		builtin_exec(char **argv, t_list *l_free);
int		ft_exit(char **argv, int status, t_list *l_free);
int		check_argv_exit(char **argv, t_list *l_free, int status);
int		ft_cd(char **argv);
int		ft_pwd(void);
int		ft_env(char **argv);
int		ft_export(char **argv);
void	print_env(void);
int		ft_unset(char **argv);
int		ft_echo(char **argv);
int		cd_no_args(void);

#endif
