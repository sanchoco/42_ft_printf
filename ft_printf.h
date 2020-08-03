/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 15:38:55 by sancho            #+#    #+#             */
/*   Updated: 2020/06/16 04:27:14 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef	struct		s_tab
{
	char			flag;
	int				width;
	int				pre;
	int				length;
	int				error_code;
}					t_tab;
int					ft_printf(const char *format, ...);
int					ft_unit_c(t_tab opt, va_list ap);
int					ft_unit_s(t_tab opt, va_list ap);
int					ft_unit_p(t_tab opt, va_list ap);
int					ft_unit_d(t_tab opt, va_list ap);
int					ft_unit_u(t_tab opt, va_list ap);
int					ft_unit_lx(t_tab opt, va_list ap);
int					ft_unit_bx(t_tab opt, va_list ap);
int					ft_unit_pct(t_tab opt);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
int					ft_strlen(char *str);
void				*ft_memset(void *b, int c, size_t n);
#endif
