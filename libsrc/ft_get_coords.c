/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:15:59 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/03/18 20:18:41 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_coords(t_coord *dst, int x, int y)
{
	if (!dst)
		return ;
	dst->x = x;
	dst->y = y;
	return ;
}
