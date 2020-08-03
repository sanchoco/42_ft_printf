/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:57:07 by sancho            #+#    #+#             */
/*   Updated: 2020/06/11 23:08:30 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unit_c(t_tab opt, va_list ap)
{
	char	c;
	int		i;
	int		value;

	value = 0;
	c = va_arg(ap, int);
	i = opt.width - 1;
	while ((opt.flag != '-') && (i-- > 0) && (++value))
		write(1, " ", 1);
	write(1, &c, 1);
	value++;
	while ((opt.flag == '-') && (i-- > 0) && (++value))
		write(1, " ", 1);
	return (value);
}
