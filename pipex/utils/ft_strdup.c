/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:39:54 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 16:39:54 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len_src;
	char	*cpy;

	i = 0;
	if (!src)
		return ((void *)0);
	len_src = ft_strlen(src);
	cpy = (char *) malloc (sizeof (char) * (len_src + 1));
	if (cpy == NULL)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}	
	cpy[i] = '\0';
	return (cpy);
}
