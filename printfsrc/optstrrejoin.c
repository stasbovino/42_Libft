/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optstrrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:08:03 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/27 20:37:58 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_optstrrejoin(char *s1, char *s2, int opt)
{
	char	*a;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	a = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[++i])
		a[i] = s1[i];
	while (s2[j])
	{
		a[i] = s2[j];
		i++;
		j++;
	}
	a[i] = '\0';
	if (opt == 1 || opt == 3)
		free(s1);
	if (opt == 2 || opt == 3)
		free(s2);
	return (a);
}
