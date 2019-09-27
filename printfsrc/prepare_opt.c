/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:27:11 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/27 20:38:08 by gwyman-m         ###   ########.fr       */
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

int					prepare_opt(char *format, size_t *begin, va_list *args)
{
	size_t		i;
	t_options	*opt;

	i = 1;
	opt = create_opt_strct();
	while (flags(opt, format[i]))
		i++;
	define_width(format, &(opt->width), &i);
	define_prec(format, &(opt->prec), &i);
	parse_len_mod(opt, format + i);
	if (opt->len_mod)
		i += ft_strlen(opt->len_mod);
	parse_type(opt, format[i]);
	*begin += (opt->type == -1) ? 0 : i;
	i = print_type(opt, args);
	free(opt);
	return (i);
}
