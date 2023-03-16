/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:27:02 by jchauvet          #+#    #+#             */
/*   Updated: 2023/03/10 10:27:15 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cd_no_args(void)
{
	char	*home;
	char	cwd[1024];

	home = env_get_value("HOME");
	if (home == NULL)
		return (1);
	if (chdir(home) != 0)
		return (1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (1);
	env_unset_var("OLDPWD");
	env_set_env("OLDPWD", env_get_value("PWD"));
	env_unset_var("PWD");
	env_set_env("PWD", cwd);
	return (0);
}
