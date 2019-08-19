/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:08:19 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/15 13:08:48 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	power(int pow)
{
	int b;

	b = 2;
	if (pow == 0)
		return (1);
	while (pow-- > 1)
		b *= 2;
	return (b);
}

static int	count_length(char *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (s[0] == 0)
		return (1);
	while (s[i++])
		len++;
	return (len);
}

int			ft_atoi_binary(char *s)
{
	int n;
	int pow;
	int	len;

	n = 0;
	len = count_length(s) - 1;
	pow = 0;
	while (len >= 0)
	{
		if (s[len] >= '0' && s[len] <= '9')
			n += (s[len] - '0') * power(pow);
		pow++;
		len--;
	}
	return (n);
}
