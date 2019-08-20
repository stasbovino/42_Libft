/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:33:49 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:35:45 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_x(uintmax_t n, t_options *opt)
{
	char					*num;
	char					*output;
	int						alt_out;
	int						letters;

	apply_len_mod_u(&n, opt->len_mod);
	letters = (opt->type == 'x') ? 0 : 1;
	num = ft_itoa_sizet(n, 16, letters);
	alt_out = (opt->alt_out == 1 && n != 0) ? 3 : 0;
	if (alt_out == 3 && opt->type == 'X')
		alt_out = 4;
	if (opt->prec == 0 && n == 0)
	{
		free(num);
		num = ft_strnew(0);
	}
	output = create_dig_output(num, opt, alt_out);
	if (!ft_strequ(num, output))
	{
		free(num);
	}
	return (count_and_free(output));
}
