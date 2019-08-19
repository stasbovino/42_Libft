/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:24:30 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/17 14:11:59 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	len += ft_numlen(n);
	return (len);
}

char			*ft_itoa(int n)
{
	char	*a;
	long	len;
	long	nb;

	nb = n;
	n = 0;
	len = ft_length(nb);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		a[0] = '-';
		n = 1;
	}
	a[len] = '\0';
	while (--len >= n)
	{
		a[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}
