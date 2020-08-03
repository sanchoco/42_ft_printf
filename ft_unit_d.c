/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:09:03 by sancho            #+#    #+#             */
/*   Updated: 2020/06/16 06:56:24 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char		*num;
	long long	l;
	int			len;

	l = (long long)n;
	len = (l > 0) ? 0 : 1;
	l = (l > 0) ? l : l * -1;
	while (n)
		n = len++ ? n / 10 : n / 10;
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memset(num, 0, len);
	num[len] = '\0';
	while (l)
	{
		num[--len] = l % 10 + '0';
		l = l / 10;
	}
	if (len != 0 && num[1] == '\0')
		num[0] = '0';
	if (len != 0 && num[1] != '\0')
		num[0] = '-';
	return (num);
}

int		ft_fill_space(t_tab opt, int len, int minus, int mode)
{
	int	i;
	int	result;
	int	temp;

	temp = (len < (opt.length + minus)) ? (opt.length + minus) : len;
	result = 0;
	i = opt.width - temp;
	while ((mode == 0) && (i-- > 0))
		result += write(1, " ", 1);
	while ((mode == 1) && (i-- > 0))
		result += write(1, "0", 1);
	return (result);
}

int		ft_fill_zero(int i)
{
	int	result;

	result = 0;
	while (i-- > 0)
		result += write(1, "0", 1);
	return (result);
}

int		ft_unit_d(t_tab opt, va_list ap)
{
	char	*nbr;
	int		value;
	int		minus;
	int		len;

	value = 0;
	nbr = ft_itoa(va_arg(ap, int));
	minus = nbr[0] == '-' ? 1 : 0;
	len = ft_strlen(nbr);
	value += ((opt.flag != '-') && !((opt.flag == '0') && (opt.pre == 0))) ?
		ft_fill_space(opt, len, minus, 0) : 0;
	(minus == 1 && ++value) ? write(1, "-", 1) : 0;
	value += ((opt.flag == '0') && (opt.pre == 0))
		? ft_fill_space(opt, len, minus, 1) : 0;
	value += ft_fill_zero(minus + opt.length - len);
	if (!(*nbr == '0' && opt.length == 0))
		value += write(1, &nbr[minus], (ft_strlen(nbr) - minus));
	if ((*nbr == '0' && opt.length == 0) && (opt.width > 0))
		value += write(1, " ", 1);
	value += (opt.flag == '-') ? ft_fill_space(opt, len, minus, 0) : 0;
	ft_memset(nbr, 0, len);
	free(nbr);
	return (value);
}
