/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:58:00 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 16:58:00 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *) malloc (sizeof (char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i] != '\0')
		dest[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dest[len++] = s2[i++];
	dest[len] = '\0';
	free(s1);
	return (dest);
}
