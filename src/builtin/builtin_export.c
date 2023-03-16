/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchauvet <jchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:50:02 by agiraud           #+#    #+#             */
/*   Updated: 2023/03/03 10:05:23 by jchauvet         ###   ########.fr       */
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
	int	i;

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
		env_set_env(ft_export_name(argv[i]), ft_export_value(argv[i]));
		i++;
	}
	return (0);
}
