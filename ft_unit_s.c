/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:57:28 by sancho            #+#    #+#             */
/*   Updated: 2020/06/16 04:57:27 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unit_s(t_tab opt, va_list ap)
{
	char	*nbr;
	int		value;
	int		i;
	int		len;

	value = 0;
	nbr = va_arg(ap, char*);
	if (nbr == NULL)
		nbr = "(null)";
	if (opt.pre == 0)
		len = ft_strlen(nbr);
	else
		len = ft_strlen(nbr) > opt.length ? opt.length : ft_strlen(nbr);
	i = opt.width - len;
	while ((opt.flag == 0) && (i-- > 0) && ++value)
		write(1, " ", 1);
	while ((opt.flag == '0') && (i-- > 0) && ++value)
		write(1, "0", 1);
	write(1, nbr, len);
	value += len;
	while (opt.flag == '-' && (i-- > 0) && ++value)
		write(1, " ", 1);
	return (value);
}
