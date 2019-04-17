/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:27:31 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/04/17 22:45:32 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	limit(unsigned long long result, int sign, int count)
{
	if ((result >= 9223372036854775807 || count > 19) && sign == 1)
		return (-1);
	else if ((result > 9223372036854775807 || count > 19) && sign == -1)
		return (0);
	else
		return (1);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					start;
	unsigned long long	result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	start = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
		if (limit(result, sign, i - start) != 1)
			return (limit(result, sign, i - start));
	}
	return (sign * result);
}
