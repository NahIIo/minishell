/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:39:17 by jchauvet          #+#    #+#             */
/*   Updated: 2023/03/10 10:24:36 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "global.h"

int		env_init(void);
char	*env_get_value(char *name);
char	*env_find_var(char *name);
bool	env_var_is_value(char *var_name, char *value);
bool	env_is_var_char(char c);
int		env_unset_var(char *name);
int		env_put_var(char *str);
int		env_set_env(char *name, char *value);

#endif
