/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:35:06 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/17 13:57:33 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_lf(long double n, t_options *opt)
{
	char	*num;
	int		signfp;
	char	*output;

	signfp = 0;
	opt->prec = (opt->prec <= -1) ? 6 : opt->prec;
	num = ft_itoa_longdouble(&n, opt, &signfp);
	output = create_float_output(num, opt, signfp);
	if (!ft_strequ(num, output))
		free(num);
	return (count_and_free(output));
}
