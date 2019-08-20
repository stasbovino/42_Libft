/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:28:15 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:33:50 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mant_double(char *mant, char *num, int denorm, int dcase)
{
	int		i;
	char	*tmp;

	num = ft_strnew(100);
	num[0] = (denorm == 1) ? '0' : '1';
	num[1] = '.';
	i = 1;
	while (++i < 99)
		num[i] = '0';
	i = -1;
	tmp = ft_strdup("1.0");
	while (++i < dcase)
	{
		divis(&tmp, 0);
		if (mant[i] == '1')
			summ(tmp, (char**)&num, 0);
	}
	i = 99;
	while (num[i - 1] == '0' && i - 1 > 8)
		i--;
	num[i] = '\0';
	free(tmp);
	return (num);
}

char	*create_fnum(char *mant, int exp, int denorm, int dcase)
{
	char	*num;
	int		i;

	i = 0;
	num = mant_double(mant, 0, denorm, (dcase == 1) ? 63 : 52);
	while (exp > 0)
	{
		summ(num, &num, 0);
		exp--;
	}
	while (exp < 0)
	{
		divis(&num, 0);
		exp++;
	}
	while (num[i + 1])
		i++;
	while (num[i] == '0' && num[i - 1] != '.')
		i--;
	num[i + 1] = '\0';
	return (num);
}
