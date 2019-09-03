/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:16:48 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 16:40:41 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		countwords(char const *s, char c)
{
	long	k;
	size_t	i;

	k = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			k++;
		}
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
		}
	}
	return (k);
}

static int		writeword(char const *s, char **a, size_t i, size_t len)
{
	size_t	k;

	k = 0;
	if (!(a[i] = (char*)malloc(sizeof(char) * (len))))
	{
		while (a[k])
		{
			ft_strdel(&a[k]);
			k++;
		}
		free(a);
		return (0);
	}
	k = 0;
	while (s[k] && k < len)
	{
		a[i][k] = s[k];
		k++;
	}
	a[i][k] = '\0';
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	long	count;
	long	nb;
	char	**a;
	size_t	start;

	nb = -1;
	count = countwords(s, c);
	if (count == -1)
		return (NULL);
	if (!(a = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	a[count] = NULL;
	while (s[i] && ++nb < count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (!writeword(s + start, a, nb, i - start))
			return (NULL);
	}
	return (a);
}
