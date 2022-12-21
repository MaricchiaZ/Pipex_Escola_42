/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:06:23 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/21 00:26:01 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_to_malloc(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (i == 0 && s[i] == c)
			i++;
		if (s[i] != c && s[i + 1] == c)
			count++;
		if (s[i] != c && s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		loc_c;
	int		i;
	int		i_tab;
	char	**tab;

	i = 0;
	loc_c = 0;
	i_tab = 0;
	tab = (char **) malloc (sizeof(char *) * (count_to_malloc(s, c) + 1));
	i = 0;
	while (s[i] && count_to_malloc(s, c) > 0)
	{
		while (s[i] && s[i] == c)
			i++;
		loc_c = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > loc_c)
		{
			tab[i_tab] = ft_substr(s, loc_c, i - loc_c);
			i_tab++;
		}
	}
	tab[i_tab] = NULL;
	return (tab);
}
