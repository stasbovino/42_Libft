/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_signfp_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:19:06 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:34:10 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	create_fsignfp(int *signfp, t_options *opt, char *bits)
{
	if (bits[0] == '1')
		*signfp = -1;
	else if (opt->sign == 1)
	{
		if (bits[0] == '0')
			*signfp = 1;
	}
	else if (opt->space == 1)
		*signfp = -2;
	else
		*signfp = 0;
}

void	set_fsignfp(char *num, int *signfp, int i)
{
	if (*signfp == -1)
		num[i] = '-';
	else if (*signfp == 1)
		num[i] = '+';
	else if (*signfp == -2)
		num[i] = ' ';
	*signfp = 0;
}
