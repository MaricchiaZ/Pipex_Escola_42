/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:38:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/22 16:40:32 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*my_path_join(char const *s1, char const *s2)
{
	char	*s;
	int		count;
	int		count2;

	count = 0; 
	count2 = 0;
	s = malloc ((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		s[count] = s1[count];
		count++;
	}
	s[count++] = '/';
	while (s2[count2] != '\0')
		s[count++] = s2[count2++];
	s[count] = '\0';
	return (s);
}

char    *get_path(char **env, char *cmd)
{
    int        i;
    char    *line;
    char    **check;
    char    *path;

    i = 0;
    while (env[i][0] != 'P' || env[i][1] != 'A'
            || env[i][2] != 'T' || env[i][3] != 'H'|| env[i][4] != '=')
        i++;
    line = env[i] + 5;
    check = ft_split(line, ':');
    i = 0;
    while (check[i] != NULL)
    {
		// /usr/local/sbin
		// /usr/local/bin
		// /usr/sbin
		// /usr/bin
		// /sbin
		// /bin/
        path = my_path_join(check[i], ft_split(cmd, ' ')[0]);
        if (access(path, F_OK | X_OK) == 0)
            return (path);
        free(path);
        i++;
    }
    exit (127);
}
