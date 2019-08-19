/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 04:21:28 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/11 18:46:29 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countchars(char const *s, char c)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			k++;
		i++;
	}
	return (k);
}
