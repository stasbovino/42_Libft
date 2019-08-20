/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_arithmetics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:10:23 by jterry            #+#    #+#             */
/*   Updated: 2019/08/20 14:34:06 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		overf(char *buf, int i)
{
	if (i == 0)
		return ;
	if (buf[buf[i - 1] == '.' ? i - 2 : i - 1] == '9')
	{
		buf[buf[i - 1] == '.' ? i - 2 : i - 1] = '0';
		overf(buf, buf[i - 1] == '.' ? i - 2 : i - 1);
	}
	else if (buf[buf[i - 1] == '.' ? i - 2 : i - 1])
	{
		buf[buf[i - 1] == '.' ? i - 2 : i - 1] += 1;
	}
	return ;
}

void		summ(char *t, char **buf, int i)
{
	while (t[i])
	{
		if (t[i] != '0' && t[i] != '.')
		{
			if ((*buf)[i] + t[i] - '0' > '9')
			{
				(*buf)[i] = (*buf)[i] + t[i] - '0' - 10;
				if (i - 1 == -1)
				{
					*buf = ft_optstrrejoin("0", (*buf), 2);
					t = *buf;
					i++;
				}
				if ((*buf)[(*buf)[i - 1] == '.' ? i - 2 : i - 1] == '9')
					overf(*buf, i);
				else
					(*buf)[(*buf)[i - 1] == '.' ? i - 2 : i - 1] += 1;
			}
			else
				(*buf)[i] += t[i] - '0';
		}
		i++;
	}
}

void		divis(char **buf, int i)
{
	while ((*buf)[i + 1])
		i++;
	while (i >= 0 && (*buf)[i])
	{
		if ((*buf)[i] == '.')
			i--;
		if (i == 0 && (*buf)[0] == '0')
			return ;
		if (((*buf)[i] - '0') % 2 == 1)
		{
			if (!(*buf)[i + 1])
				*buf = ft_optstrrejoin(*buf, "0", 1);
			(*buf)[(*buf)[i + 1] == '.' ? i + 2 : i + 1] += 5;
		}
		(*buf)[i] = (((*buf)[i] - '0') / 2) + '0';
		i--;
	}
}
