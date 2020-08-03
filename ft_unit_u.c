/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:59:31 by sancho            #+#    #+#             */
/*   Updated: 2020/06/16 06:58:01 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(unsigned int n)
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
	ft_memset(num, 0, len + 1);
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

int		ft_fill_space_u(t_tab opt, int len, int mode)
{
	int	i;
	int	result;
	int	temp;

	temp = (len < opt.length) ? opt.length : len;
	result = 0;
	i = opt.width - temp;
	while ((mode == 0) && (i-- > 0))
		result += write(1, " ", 1);
	while ((mode == 1) && (i-- > 0))
		result += write(1, "0", 1);
	return (result);
}

int		ft_fill_zero_u(int i)
{
	int	result;

	result = 0;
	while (i-- > 0)
		result += write(1, "0", 1);
	return (result);
}

int		ft_unit_u(t_tab opt, va_list ap)
{
	char	*nbr;
	int		value;
	int		len;

	value = 0;
	nbr = ft_itoa_u(va_arg(ap, unsigned int));
	len = ft_strlen(nbr);
	value += ((opt.flag != '-') && !((opt.flag == '0') && (opt.pre == 0))) ?
		ft_fill_space_u(opt, len, 0) : 0;
	value += ((opt.flag == '0') && (opt.pre == 0))
		? ft_fill_space_u(opt, len, 1) : 0;
	value += ft_fill_zero_u(opt.length - len);
	if (!(*nbr == '0' && opt.length == 0))
		value += write(1, nbr, ft_strlen(nbr));
	if ((*nbr == '0' && opt.length == 0) && (opt.width > 0))
		value += write(1, " ", 1);
	value += (opt.flag == '-') ? ft_fill_space_u(opt, len, 0) : 0;
	ft_memset(nbr, 0, len);
	free(nbr);
	return (value);
}
