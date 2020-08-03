/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:28:54 by sancho            #+#    #+#             */
/*   Updated: 2020/06/16 07:04:42 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	ft_make_opt(void)
{
	t_tab opt;

	opt.flag = 0;
	opt.width = -1;
	opt.pre = 0;
	opt.length = -1;
	opt.error_code = 0;
	return (opt);
}

t_tab	ft_opt_parsing(char c, t_tab opt, va_list ap)
{
	if ((c == '-' || c == '0') && (opt.width == -1) && (opt.length == -1) &&
	opt.flag == 0)
		opt.flag = c;
	else if (c == '.' && (opt.pre = 1))
		opt.length = 0;
	else if ((opt.pre == 0) && (ft_strchr("0123456789", c)))
		opt.width = opt.width == -1 ? (c - '0') : opt.width * 10 + (c - '0');
	else if ((opt.pre == 1) && (ft_strchr("0123456789", c)))
		opt.length = opt.length == -1 ? c - '0' : opt.length * 10 + (c - '0');
	else if (c == '*' && opt.pre == 0)
	{
		opt.width = va_arg(ap, int);
		opt.flag = (opt.width < 0) ? '-' : opt.flag;
		opt.width = (opt.width < 0) ? (-1 * opt.width) : opt.width;
	}
	else if ((c == '*') && (opt.pre == 1) && (opt.length = va_arg(ap, int)))
		((opt.length < 0) && !(opt.pre = 0)) ?
			opt.length = -1 : 0;
	else
		opt.error_code = -1;
	return (opt);
}

int		ft_specifier(char c, t_tab opt, va_list ap)
{
	int result;

	result = 0;
	if (c == 'c')
		result = ft_unit_c(opt, ap);
	else if (c == 's')
		result = ft_unit_s(opt, ap);
	else if (c == 'p')
		result = ft_unit_p(opt, ap);
	else if (c == 'd' || c == 'i')
		result = ft_unit_d(opt, ap);
	else if (c == 'u')
		result = ft_unit_u(opt, ap);
	else if (c == 'x')
		result = ft_unit_lx(opt, ap);
	else if (c == 'X')
		result = ft_unit_bx(opt, ap);
	else if (c == '%')
		result = ft_unit_pct(opt);
	else
		result = -1;
	return (result);
}

int		ft_parsing(const char *format, int i, va_list ap, int *result)
{
	t_tab	opt;

	opt = ft_make_opt();
	if ((char)format[i] == 0)
		return (-1);
	while (format[i])
	{
		if (ft_strchr("cspdiuxX%", (char)format[i]))
		{
			*result += ft_specifier((char)format[i], opt, ap);
			return (i++);
		}
		else if (ft_strchr("-.*0123456789", (char)format[i]))
			opt = ft_opt_parsing((char)format[i], opt, ap);
		else
			return (i);
		i++;
	}
	if (opt.error_code == -1)
		*result = 0;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		result;
	int		i;

	va_start(ap, format);
	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_parsing(format, ++i, ap, &result);
		else
		{
			write(1, &format[i], 1);
			result++;
		}
		if ((result == -1) || (i == -1) || (format[i] == 0))
		{
			va_end(ap);
			return (result);
		}
		i++;
	}
	va_end(ap);
	return (result);
}
