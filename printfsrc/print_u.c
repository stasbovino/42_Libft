/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:33:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:35:40 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_u(uintmax_t n, t_options *opt)
{
	char					*num;
	char					*output;

	apply_len_mod_u(&n, opt->len_mod);
	num = ft_itoa_sizet(n, 10, 0);
	if (opt->prec == 0 && n == 0)
	{
		free(num);
		num = ft_strnew(0);
	}
	output = create_dig_output(num, opt, 0);
	if (!ft_strequ(num, output))
		free(num);
	return (count_and_free(output));
}
