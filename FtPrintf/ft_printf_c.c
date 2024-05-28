/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:22:24 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/21 22:57:45 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printfspec(int *p_count)
{
	(*p_count)++;
	if (write (1, "%", 1) != -1)
	{
		(*p_count)++;
		return (1);
	}
	return (0);
}

int	ft_printfc(unsigned char c, int *p_count)
{
	(*p_count)++;
	if (c == 0)
	{
		(*p_count)++;
		write(1, "", 1);
		return (1);
	}
	if (!c)
	{
		(*p_count) += 6;
		write(1, "(null)", 6);
		return (1);
	}
	if (write (1, &c, 1) != -1)
	{
		(*p_count)++;
		return (1);
	}
	return (0);
}
