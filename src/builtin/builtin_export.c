/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:50:02 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/16 12:41:40 by jchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*ft_export_name(char *str)
{
	char	*name;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (NULL);
	name = ft_substr(str, 0, i);
	return (name);
}

char	*ft_export_value(char *str)
{
	char	*value;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (ft_strdup(""));
	value = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	return (value);
}

int	ft_export(char **argv)
{
	int		i;
	char	*ex_name;
	char	*ex_val;

	i = 1;
	if (!argv[i])
		print_env();
	while (argv[i])
	{
		if (!ft_isalpha(argv[1][0]))
		{
			print_error(SHELL_NAME, "export", argv[1],
				"not a valid identifier");
			return (1);
		}
		ex_name = ft_export_name(argv[i]);
		ex_val = ft_export_value(argv[i]);
		env_set_env(ex_name, ex_val);
		free(ex_name);
		free(ex_val);
		i++;
	}
	return (0);
}
