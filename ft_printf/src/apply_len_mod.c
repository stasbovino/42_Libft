/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_len_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 19:24:59 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/15 21:36:46 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_len_mod_u(uintmax_t *n, char *len_mod)
{
	if (len_mod == NULL)
		*n = (unsigned int)*n;
	else if (ft_strequ(len_mod, "hh"))
		*n = (unsigned char)*n;
	else if (ft_strequ(len_mod, "h"))
		*n = (unsigned short int)*n;
	else if (ft_strequ(len_mod, "l"))
		*n = (unsigned long int)*n;
	else if (ft_strequ(len_mod, "ll"))
		*n = (unsigned long long int)*n;
}

void	apply_len_mod(intmax_t *n, char *len_mod)
{
	if (len_mod == NULL)
		*n = (int)*n;
	else if (ft_strequ(len_mod, "hh"))
		*n = (signed char)*n;
	else if (ft_strequ(len_mod, "h"))
		*n = (short int)*n;
	else if (ft_strequ(len_mod, "l"))
		*n = (long int)*n;
	else if (ft_strequ(len_mod, "ll"))
		*n = (long long int)*n;
}
