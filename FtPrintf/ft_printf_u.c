/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:08:19 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/21 22:51:59 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(unsigned int n)
{
	int				mem_space;
	unsigned int	nbr;
	char			*result;

	nbr = n;
	mem_space = 1;
	while (n > 9)
	{
		n = n / 10;
		mem_space++;
	}
	result = malloc(mem_space + 1);
	if (!result)
		return (NULL);
	result[mem_space] = '\0';
	while (--mem_space > -1)
	{
		result[mem_space] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (result);
}

int	ft_printfu(unsigned int i, int *p_count)
{
	char	*s;
	char	*add_s;

	(*p_count)++;
	s = ft_itoa_u(i);
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
