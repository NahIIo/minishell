/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:33:14 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/15 16:06:59 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <sys/stat.h>
/* 
char	*get_first_directory(char *newpwd)
{
	int		i;
	char	*first_pwd;

	i = 1;
	while (newpwd[i] && newpwd[i] != '/')
		i++;
	first_pwd = malloc(sizeof(char) * (i + 1));
	if (first_pwd == NULL)
		return (NULL);
	i = 1;
	first_pwd[0] = '/';
	while (newpwd[i] != '/')
	{
		first_pwd[i] = newpwd[i];
		i++;
	}
	first_pwd[i] = '\0';
	//free(newpwd);
	return (first_pwd);
}

void	update_pwd(int status, char *cwd)
{
	char	*oldpwd;
	char	*newpwd;
	char	*pwd;

	if (status == 42)
	{
		oldpwd = env_get_value("PWD");
		newpwd = ft_strdup(cwd);
		newpwd = get_first_directory(newpwd);
		pwd = ft_strjoin(oldpwd, newpwd);
		//free(newpwd);
		env_unset_var("OLDPWD");
		env_set_env("OLDPWD", env_get_value("PWD"));
		env_unset_var("PWD");
		env_set_env("PWD", pwd);
		//free(pwd);
	}
	else
	{
		env_unset_var("OLDPWD");
		env_set_env("OLDPWD", env_get_value("PWD"));
		env_unset_var("PWD");
		env_set_env("PWD", cwd);
	}
}

int	verif_access(char *path)
{
	if (access(path, F_OK) == -1)
	{
		print_error(SHELL_NAME, "cd", path, "No such file or directory");
		return (1);
	}
	if (access(path, X_OK) == -1)
	{
		print_error(SHELL_NAME, "cd", path, "Permission denied");
		return (1);
	}
	return (0);
}

int	cd_one_arg(char *path)
{
	char		cwd[1024];
	struct stat	sb;
	int			status;

	if (verif_access(path) == 1)
		return (1);
	status = lstat(path, &sb);
	if (S_ISLNK(sb.st_mode))
		status = 42;
	if (chdir(path) != 0)
		return (1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (1);
	update_pwd(status, cwd);
	return (0);
}

int	ft_cd(char **args)
{
	if (args[1] == NULL)
	{
		if (cd_no_args() != 0)
			return (1);
	}
	else if (args[2] == NULL)
	{
		if (cd_one_arg(args[1]) != 0)
			return (1);
	}
	else
	{
		print_error(SHELL_NAME, "cd", NULL, "too many arguments");
		return (1);
	}
	return (0);
} */

/*************************SECOND METHOD******************************/

char	*add_home_path(char *path)
{
	char		*tmp;
	char		*tmpp;

	if (ft_strncmp(path, "~/", 2) == 0)
	{
		if ((tmp = env_get_value("HOME")))
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

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		if (pwd)
		{
			env_set_env("OLDPWD", pwd);
			free(pwd);
		}
		if ((pwd = getcwd(NULL, 0)))
		{
			env_set_env("PWD", pwd);
			free(pwd);
		}
		return (1);
	}
	free(pwd);
	return (0);
}

int			set_directory(char *path)
{
	struct stat	st;

	if (change(path) == 1)
		return (1);
	if (stat(path, &st) == -1)
		print_error(SHELL_NAME, "cd", path, "No such file or directory");
	else if (!(st.st_mode & S_IXUSR))
		print_error(SHELL_NAME, "cd", path, "Permission denied");
	else
		print_error(SHELL_NAME, "cd", path, "Not a directory");
	return (1);
}

int			ft_cd(char **args)
{
	char	*home;

	home = NULL;
	if (args && args[1] && args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (1);
	}
	if (!args[1] || !ft_strcmp(args[1], "~"))
	{
		if (!(home = env_get_value("HOME")))
		{
			print_error(SHELL_NAME, "cd", NULL, "HOME not set");
			return (1);
		}
		return (set_directory(home));
	}
	args[1] = add_home_path(args[1]);
	return (set_directory(args[1]));
}
