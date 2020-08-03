/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:59:01 by sancho            #+#    #+#             */
/*   Updated: 2020/06/16 06:57:33 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_p(long long n)
{
	char		*num;
	long long	l;
	int			len;
	char		*hex;

	hex = ft_strdup("0123456789abcdef");
	l = (long long)n;
	len = (l > 0) ? 0 : 1;
	l = (l > 0) ? l : l * -1;
	while (n)
		n = len++ ? n / 16 : n / 16;
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memset(num, 0, len + 1);
	num[len] = '\0';
	while (l)
	{
		num[--len] = hex[l % 16];
		l = l / 16;
	}
	if (len != 0 && num[1] == '\0')
		num[0] = '0';
	free(hex);
	return (num);
}

int		ft_fill_space_p(t_tab opt, int len, int mode)
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

int		ft_fill_zero_p(int i)
{
	int	result;

	result = 0;
	while (i-- > 0)
		result += write(1, "0", 1);
	return (result);
}

int		ft_unit_p(t_tab opt, va_list ap)
{
	char	*nbr;
	int		value;
	int		len;

	value = 0;
	nbr = ft_itoa_p(va_arg(ap, long long));
	len = ft_strlen(nbr) + 2;
	if ((*nbr == '0' && opt.length == 0))
		value += ft_fill_space_p(opt, len - 1, 0);
	else
		value += ((opt.flag != '-') && !((opt.flag == '0') && (opt.pre == 0))) ?
			ft_fill_space_p(opt, len, 0) : 0;
	value += write(1, "0x", 2);
	value += ((opt.flag == '0') && (opt.pre == 0))
		? ft_fill_space_p(opt, len, 1) : 0;
	value += ft_fill_zero_p(opt.length - len + 2);
	if (!(*nbr == '0' && opt.length == 0))
		value += write(1, nbr, ft_strlen(nbr));
	value += (opt.flag == '-') ? ft_fill_space_p(opt, len, 0) : 0;
	ft_memset(nbr, 0, len);
	free(nbr);
	return (value);
}
