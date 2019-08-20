/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signfp_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:34:09 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:35:55 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** signfp values:
** -2 = space
** -1 = minus
**  0  = no sign
**  1 = plus
**  2 = zero
*/

void	set_len_from_signfp(int *len, int signfp)
{
	if (signfp != 0)
		(*len)++;
	if (signfp == 3 || signfp == 4)
		(*len)++;
}

void	set_sign(char *s, int *signfp, int *i, int side)
{
	if (*signfp == 1)
		s[*i] = '+';
	else if (*signfp == -1)
		s[*i] = '-';
	else if (*signfp == 2)
		s[*i] = '0';
	else if (*signfp == 3 || *signfp == 4)
	{
		if (side == -1)
		{
			s[0] = '0';
			s[1] = (*signfp == 3) ? 'x' : 'X';
			(*i)++;
		}
		else
		{
			s[(*i)--] = (*signfp == 3) ? 'x' : 'X';
			s[(*i)] = '0';
		}
	}
	else if (*signfp == -2)
		s[*i] = ' ';
	if (side == 1)
		*signfp = 0;
}

void	create_signfp(int *signfp, t_options *opt, intmax_t n)
{
	if (n < 0)
		*signfp = -1;
	else if (opt->sign == 1)
		*signfp = 1;
	else if (opt->space == 1)
		*signfp = -2;
	else if (opt->type == 'o' && opt->alt_out == 1)
		*signfp = 2;
	else
		*signfp = 0;
}
