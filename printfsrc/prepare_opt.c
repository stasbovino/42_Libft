/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:27:11 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/11/05 18:56:15 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_options	*create_opt_strct(void)
{
	t_options *new;

	new = (t_options*)malloc(sizeof(t_options));
	new->left_side = -1;
	new->sign = -1;
	new->space = -1;
	new->alt_out = -1;
	new->zeros = -1;
	new->width = -1;
	new->prec = -1;
	new->len_mod = NULL;
	new->type = -1;
	return (new);
}

void				wdcd(int *dst, va_list *args, size_t *inc, int opt)
{
	*dst = va_arg(*args, int);
	*inc += 1;
	if (opt == 1)
		*inc += 1;
}

int					prepare_opt(char *format, size_t *begin, va_list *args)
{
	size_t		i;
	t_options	*opt;

	i = 1;
	opt = create_opt_strct();
	while (flags(opt, format[i]))
		i++;
<<<<<<< HEAD
	define_width(format, &(opt->width), &i, args);
	define_prec(format, &(opt->prec), &i);
=======
	format[i] == '*' ? wdcd(&(opt->width), args, &i, 0) :
		define_width(format, &(opt->width), &i);
	(format[i] == '.' && format[i + 1] == '*') ?
		wdcd(&(opt->prec), args, &i, 1) : define_prec(format, &(opt->prec), &i);
>>>>>>> b580b53fc9cb1cdf1f9b531b0750d4a1eca2a1f2
	parse_len_mod(opt, format + i);
	if (opt->len_mod)
		i += ft_strlen(opt->len_mod);
	parse_type(opt, format[i]);
	*begin += (opt->type == -1) ? 0 : i;
	i = print_type(opt, args);
	free(opt);
	return (i);
}
