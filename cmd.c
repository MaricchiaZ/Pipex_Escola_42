/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:37:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/22 16:38:00 by maclara-         ###   ########.fr       */
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
	while (s[i] != '\0') //     "   tr 'c' e"
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

static void	my_cmd_split(char	*s, char **matriz, int n, int strcount)
{
	int	start;

	start = 0;
	while (s[n] != '\0')
	{
		while (s[n] == ' ')
			n++;
		start = n;
		if (s[n] == '\'' || s[n] == '\"') //  "   tr 'c' e"
		{
			n++;
			start++;
			while (s[n] != s[start - 1] && s[n] != '\0')
				n++;
			matriz[strcount++] = ft_substr(s, start, n - start);
			if (s[n] == s[start - 1])
				n++;
		}
		else
		{
			while (s[n] != ' ' && s[n] != '\0')
				n++;
			matriz[strcount++] = ft_substr(s, start, n - start);
		}
	}
}

char	**get_cmd(char *s)
{
	char	**ret;
	int		n;
	int		strcount;

	ret = (char **) malloc (sizeof(char *) * (get_cmd_count(s) + 1));
	if (ret == NULL)
		return (NULL);
	n = 0;
	strcount = 0;
	my_cmd_split(s, ret, n, strcount);
	ret[get_cmd_count(s)] = NULL;
	return (ret);
}
