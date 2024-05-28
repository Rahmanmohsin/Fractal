/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xcap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:24:50 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/21 22:52:03 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_memcalc_xcap(unsigned int n)
{
	unsigned long	sigfig;
	char			*result;
	int				memspace;

	sigfig = 1;
	memspace = 1;
	while (sigfig * 16 <= n)
	{
		sigfig = sigfig * 16;
		memspace++;
	}
	result = malloc(memspace + 1);
	if (!result)
		return (NULL);
	result[memspace] = '\0';
	while (--memspace > -1)
	{
		if (n % 16 > 9)
			result[memspace] = ((n % 16) + 55);
		else
			result[memspace] = ((n % 16) + 48);
		n = n / 16;
	}
	return (result);
}

int	ft_printfxcap(unsigned int n, int *p_count)
{
	char	*result;
	char	*add_res;

	(*p_count)++;
	result = ft_memcalc_xcap(n);
	if (!result)
		return (0);
	add_res = result;
	while (*result)
	{
		if (write(1, result, 1) == -1)
			return (free(add_res), 0);
		result++;
		(*p_count)++;
	}
	free(add_res);
	return (1);
}
