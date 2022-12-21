/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:41:08 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 16:41:08 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*dest;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= len)
		len = len_s - start;
	if (start > len_s)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *) s + start, len + 1);
	return (dest);
}
