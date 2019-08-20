/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:25:19 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:34:26 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		length(size_t n, size_t base)
{
	int		len;

	len = 1;
	while (n > (base - 1))
	{
		len++;
		n /= base;
	}
	return (len);
}

char	*ft_itoa_sizet(size_t nb, size_t base, int uppercase)
{
	char	*a;
	int		len;
	int		i;

	i = 0;
	len = 0;
	len = length(nb, base);
	a = ft_strnew(len);
	a[len] = '\0';
	while (--len >= 0)
	{
		if (nb % base > 9)
			a[len] = (uppercase == 1) ?
				nb % base + 'A' - 10 : nb % base + 'a' - 10;
		else
			a[len] = nb % base + '0';
		nb /= base;
	}
	return (a);
}
