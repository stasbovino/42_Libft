/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:32:53 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/20 14:35:33 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_and_free(char *buff)
{
	int len;

	ft_putstr(buff);
	len = ft_strlen(buff);
	free(buff);
	return (len);
}

int	print_type(t_options *opt, va_list *args)
{
	if (opt->type == '%')
		return (print_c('%', opt));
	else if (opt->type == 'c')
		return (print_c(va_arg(*args, int), opt));
	else if (opt->type == 's')
		return (print_s(va_arg(*args, char*), opt));
	else if (opt->type == 'p')
		return (print_p(va_arg(*args, void*), opt));
	else if (opt->type == 'd' || opt->type == 'i')
		return (print_d(va_arg(*args, intmax_t), opt));
	else if (opt->type == 'u')
		return (print_u(va_arg(*args, uintmax_t), opt));
	else if (opt->type == 'o')
		return (print_o(va_arg(*args, uintmax_t), opt));
	else if (opt->type == 'x' || opt->type == 'X')
		return (print_x(va_arg(*args, uintmax_t), opt));
	else if ((opt->type == 'F' || opt->type == 'f') &&
			opt->len_mod && ft_strequ(opt->len_mod, "L"))
		return (print_lf(va_arg(*args, long double), opt));
	else if (opt->type == 'f' || opt->type == 'F')
		return (print_f(va_arg(*args, double), opt));
	else
		return (0);
}
