/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:28:25 by sancho            #+#    #+#             */
/*   Updated: 2020/06/11 23:11:10 by sancho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return ((char*)0);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	int		index;
	char	*str;

	size = 0;
	while (s1[size])
		size++;
	if (!(str = malloc(sizeof(*s1) * size + 1)))
		return ((char*)0);
	index = 0;
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

int		ft_strlen(char *str)
{
	unsigned int index;

	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char*)(b + i) = c;
		i++;
	}
	return (b);
}
