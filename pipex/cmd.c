/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:37:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 14:04:41 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_cmd_count(char *s)
{
	int		i;
	int		n;
	char	c;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		if ((s[i] == '\'' || s[i] == '\"') && s[i + 1] != '\0')
		{
			c = s[i];
			i++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
			n++;
		}
		else if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static void	my_cmd_split(char	*s, char **matriz, int i, int strcount)
{
	int	start;

	start = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		start = i;
		if (!(s[i] == '\'' || s[i] == '\"'))
		{
			while (s[i] != ' ' && s[i] != '\0')
				i++;
			matriz[strcount++] = ft_substr(s, start, i - start);
		}
		else
		{
			i++;
			start++;
			while (s[i] != s[start - 1] && s[i] != '\0')
				i++;
			matriz[strcount++] = ft_substr(s, start, i - start);
			if (s[i] == s[start - 1])
				i++;
		}
	}
}

char	**get_cmd(char *s)
{
	char	**cmd_n_spc;
	int		i;
	int		strcount;

	cmd_n_spc = (char **) malloc (sizeof(char *) * (get_cmd_count(s) + 1));
	if (cmd_n_spc == NULL)
		return (NULL);
	i = 0;
	strcount = 0;
	my_cmd_split(s, cmd_n_spc, i, strcount);
	cmd_n_spc[get_cmd_count(s)] = NULL;
	return (cmd_n_spc);
}
