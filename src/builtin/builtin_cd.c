/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:33:14 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/20 09:30:09 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <sys/stat.h>

char	*add_home_path(char *path)
{
	char		*tmp;
	char		*tmpp;

	tmp = env_get_value("HOME");
	if (ft_strncmp(path, "~/", 2) == 0)
	{
		if (tmp)
		{
			tmpp = ft_substr(path, 1, ft_strlen(path));
			path = ft_strjoin(tmp, tmpp);
			free(tmpp);
			return (path);
		}
	}
	return (path);
}

int	change(char *path)
{
	char	*pwd;
	char	*new_pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		if (pwd)
		{
			env_set_env("OLDPWD", pwd);
			free(pwd);
		}
		new_pwd = getcwd(NULL, 0);
		if (new_pwd)
		{
			env_set_env("PWD", new_pwd);
			free(new_pwd);
		}
		return (1);
	}
	free(pwd);
	return (0);
}

int	set_directory(char *path)
{
	struct stat	st;

	if (change(path) == 1)
		return (0);
	if (stat(path, &st) == -1)
	{
		print_error(SHELL_NAME, "cd", path, "No such file or directory");
		return (1);
	}
	else if (!(st.st_mode & S_IXUSR))
	{
		print_error(SHELL_NAME, "cd", path, "Permission denied");
		return (1);
	}
	else
	{
		print_error(SHELL_NAME, "cd", path, "Not a directory");
		return (1);
	}
	return (0);
}

int	ft_cd(char **args)
{
	char	*home;

	home = env_get_value("HOME");
	if (args && args[1] && args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		if (!home)
		{
			print_error(SHELL_NAME, "cd", NULL, "HOME not set");
			return (1);
		}
		return (set_directory(home));
	}
	args[1] = add_home_path(args[1]);
	return (set_directory(args[1]));
}
