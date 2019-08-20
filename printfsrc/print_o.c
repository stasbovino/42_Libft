/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:31:14 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:35:19 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_o(uintmax_t n, t_options *opt)
{
	char					*num;
	char					*output;
	int						alt_out;

	apply_len_mod_u(&n, opt->len_mod);
	num = ft_itoa_sizet(n, 8, 0);
	alt_out = (opt->alt_out == 1) ? 2 : 0;
	if (n == 0 && opt->alt_out == 1)
	{
		free(num);
		num = ft_strdup("0");
		alt_out = 0;
	}
	else if (opt->prec == 0 && n == 0)
	{
		free(num);
		num = ft_strnew(0);
	}
	output = create_dig_output(num, opt, alt_out);
	if (!ft_strequ(num, output))
		free(num);
	return (count_and_free(output));
}
