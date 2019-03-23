/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpaste.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:36:13 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/21 20:03:58 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_joinlen(char const *s1, char const *s2)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 == 0 && len2 == 0)
		return (1);
	return (len1 + len2);
}


char		*ft_strpaste(char *from, char *to, size_t place)
{
	size_t	i;
	char	*result;
	size_t	len;

	i = 0;
	if (!to || !from)
		return (NULL);
	len = ft_joinlen(from, to);
	if (place > ft_strlen(to))
		return (NULL);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
}
