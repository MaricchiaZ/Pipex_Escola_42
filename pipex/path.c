/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:38:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 13:56:47 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*my_path_join(char const *path, char const *cmd)
{
	char	*p_c;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	p_c = malloc ((ft_strlen(path) + ft_strlen(cmd) + 2) * sizeof(char));
	if (p_c == NULL)
		return (NULL);
	while (path[i] != '\0')
	{
		p_c[i] = path[i];
		i++;
	}
	p_c[i++] = '/';
	while (cmd[i2] != '\0')
		p_c[i++] = cmd[i2++];
	p_c[i] = '\0';
	return (p_c);
}

static char	*check_path(char **check, char **cmd_name, int i)
{
	char	*path;

	while (check[i] != NULL)
	{
		path = my_path_join(check[i], cmd_name[0]);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_matrix(cmd_name);
			free_matrix(check);
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_path(char **env, char *cmd)
{
	int		i;
	char	*line;
	char	**check;
	char	*path;
	char	**cmd_name;

	i = 0;
	while (env[i][0] != 'P' || env[i][1] != 'A' \
			|| env[i][2] != 'T' || env[i][3] != 'H' || env[i][4] != '=')
		i++;
	line = env[i] + 5;
	check = ft_split(line, ':');
	cmd_name = ft_split(cmd, ' ');
	i = 0;
	path = check_path (check, cmd_name, i);
	if (path)
		return (path);
	free_matrix(cmd_name);
	free_matrix(check);
	return (NULL);
}
