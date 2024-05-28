/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:03:47 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/21 22:51:56 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_memcalc_d(int n)
{
	int		sig_fig;

	sig_fig = 1;
	if (n < 0)
	{
		n = n * -1;
		sig_fig++;
	}
	while (n > 9)
	{
		n = n / 10;
		sig_fig++;
	}
	return (sig_fig);
}

char	*ft_itoa(int n)
{
	int		mem_space;
	char	*result;
	int		sign;

	if (n == -2147483648)
		return (result = ft_strdup("-2147483648"));
	sign = 0;
	mem_space = ft_memcalc_d(n);
	result = malloc(mem_space + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	result[mem_space] = '\0';
	while (--mem_space > -1)
	{
		result[mem_space] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}

int	ft_printfd(int i, int *p_count)
{
	char	*s;
	char	*add_s;

	(*p_count)++;
	s = ft_itoa(i);
	if (!s)
		return (0);
	add_s = s;
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (free(add_s), 0);
		(*p_count)++;
		s++;
	}
	free(add_s);
	return (1);
}
