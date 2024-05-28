/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:23 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/21 22:51:51 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfs(char *s, int *p_count)
{
	(*p_count)++;
	if (!s)
	{
		(*p_count) += 6;
		if (write(1, "(null)", 6) == -1)
			return (0);
		return (1);
	}
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (0);
		(*p_count)++;
		s++;
	}
	return (1);
}
