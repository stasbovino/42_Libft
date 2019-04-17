/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 05:09:56 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/17 23:02:39 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long			ft_length(long n, int osn)
{
	long	len;

	len = 1;
	while (n > (osn - 1))
	{
		n /= osn;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(long n, int osn, int case)
{
	char	*a;
	long	len;
	int		end;

	if (osn > 16 || osn < 2 || case < 0 || case > 1)
		return ("0");
	if (n == -9223372036854775807 - 1)
		return ("-9223372036854775808");
	len = (n < 0) ? 1 : 0;
	end = (n < 0) ? 1 : 0;
	len += ft_length(n, osn);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	a[len] = '\0';
	if (end == 1)
		a[0] = '-';
	while (--len >= end)
	{
		if (n % osn > 9)
			a[len] = (case == 1) ? n % osn + 'A' - 10 : n % osn + 'a' - 10;
		else
			a[len] = n % osn + '0';
		n /= osn;
	}
	return (a);
}
