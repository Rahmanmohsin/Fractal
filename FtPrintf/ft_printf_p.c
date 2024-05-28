/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:02:38 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/21 22:51:54 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_memcalc_p(int memspace, unsigned long n)
{
	while (n > 0)
	{
		n = n / 16;
		memspace++;
	}
	return (memspace);
}

char	*ft_setp(unsigned long n)
{
	char			*result;
	int				memspace;

	if (n == 0)
		memspace = 3;
	else
		memspace = 2;
	memspace = ft_memcalc_p(memspace, n);
	result = malloc(memspace + 1);
	if (!result)
		return (NULL);
	result[memspace] = '\0';
	result[0] = '0';
	result[1] = 'x';
	while (--memspace >= 2)
	{
		if (n % 16 > 9)
			result[memspace] = ((n % 16) + 87);
		else
			result[memspace] = ((n % 16) + 48);
		n = n / 16;
	}
	return (result);
}

int	ft_printfp(unsigned long n, int *p_count)
{
	char	*result;
	char	*add_result;

	(*p_count)++;
	result = ft_setp(n);
	if (!result)
	{
		if (write(1, "0x", 2) == -1)
			return (0);
		(*p_count) += 2;
		return (0);
	}
	add_result = result;
	while (*result)
	{
		if (write(1, result, 1) == -1)
			return (free(add_result), 0);
		result++;
		(*p_count)++;
	}
	free(add_result);
	return (1);
}
