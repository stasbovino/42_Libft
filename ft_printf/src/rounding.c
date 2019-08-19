/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 13:09:59 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/18 20:17:52 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*check_intpart(char *n, char *num, int *i)
{
	if (n[0] == '9' && num[0] == '0')
	{
		num = ft_optstrrejoin("1", num, 2);
		*i += 1;
	}
	free(n);
	return (num);
}

static void	fill_with_zeros(char **num, t_options *opt, int i, int *j)
{
	while ((*num)[i + *j] && *j < opt->prec)
	{
		if (!(*num)[i + *j + 1])
			*num = ft_optstrrejoin(*num, "0", 1);
		(*j)++;
	}
}

static int	banker_rounding(char *num, int i, int j)
{
	if (num[i + j + 1] == '5'
			&& !num[i + j + 2]
			&& ((num[i + j] - '0') % 2) == 0)
		return (1);
	return (0);
}

char		*rounding(char *num, t_options *opt, int i, int j)
{
	char *n;

	n = ft_strdup(num);
	while (num[i] != '.')
		i++;
	if (opt->prec == 0)
	{
		if (num[i + 1] > '4' && !(num[i + 1] == '5' && !num[i + 2] &&
					((num[i - 1] - '0') % 2 == 0)))
			overf(num, i + 1);
		if (opt->alt_out == 1)
			i++;
		num[i] = '\0';
	}
	fill_with_zeros(&num, opt, i, &j);
	if (num[i + j + 1] && num[i + j + 1] > '4' && !banker_rounding(num, i, j))
		overf(num, i + j + 1);
	num = check_intpart(n, num, &i);
	if (num[i + j + 1])
	{
		if (num[i + j] == '.' && opt->alt_out != 1)
			i--;
		num[i + j + 1] = '\0';
	}
	return (num);
}
