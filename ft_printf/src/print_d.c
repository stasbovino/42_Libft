/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:30:56 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/15 21:34:05 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(intmax_t n, t_options *opt)
{
	char			*num;
	int				signfp;
	long long int	nb;
	char			*output;

	apply_len_mod(&n, opt->len_mod);
	num = NULL;
	nb = (n < 0) ?
		(long long int)n * -1 : (long long int)n;
	create_signfp(&signfp, opt, n);
	if (opt->prec == 0 && nb == 0)
		num = ft_strnew(0);
	else
		num = ft_itoa_sizet(nb, 10, 0);
	output = create_dig_output(num, opt, signfp);
	if (!ft_strequ(num, output))
		free(num);
	return (count_and_free(output));
}
