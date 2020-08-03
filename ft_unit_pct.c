/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_pct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:08:40 by sancho            #+#    #+#             */
/*   Updated: 2020/06/15 14:42:54 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unit_pct(t_tab opt)
{
	int value;
	int	i;

	value = 1;
	i = opt.width - 1;
	while (opt.flag == '0' && (i-- > 0) && ++value)
		write(1, "0", 1);
	while (opt.flag == 0 && (i-- > 0) && ++value)
		write(1, " ", 1);
	write(1, "%", 1);
	while (opt.flag == '-' && (i-- > 0) && ++value)
		write(1, " ", 1);
	return (value);
}
