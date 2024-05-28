/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:28:38 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/22 08:40:14 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	analysise_str(char c, va_list arg_list, int *p_count)
{
	int	rtn;

	rtn = 1;
	if (c == 'c')
		rtn = ft_printfc(va_arg(arg_list, int), p_count);
	else if (c == 'd' || c == 'i')
		rtn = ft_printfd(va_arg(arg_list, int), p_count);
	else if (c == 's')
		rtn = ft_printfs(va_arg(arg_list, char *), p_count);
	else if (c == 'p')
		rtn = ft_printfp(((unsigned long)va_arg(arg_list, void *)), p_count);
	else if (c == 'u')
		rtn = ft_printfu(va_arg(arg_list, unsigned int), p_count);
	else if (c == 'x')
		rtn = ft_printx(va_arg(arg_list, unsigned int), p_count);
	else if (c == 'X')
		rtn = ft_printfxcap(va_arg(arg_list, unsigned int), p_count);
	else if (c == '%')
		rtn = ft_printfspec(p_count);
	else
		return (0);
	return (rtn);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg_list;
	int		p_count;

	va_start(arg_list, input);
	p_count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			if (analysise_str(*(input + 1), arg_list, &p_count) == 0)
				return (-1);
			input++;
			p_count--;
		}
		else
		{
			if (write(1, input, 1) == -1)
				return (-1);
			p_count++;
		}
		input++;
	}
	va_end(arg_list);
	return (p_count);
}
// int main()
// {
// 	printf("printf:");
// 	int j = printf(" %c %.2f ", '0', 0, '1');
// 	printf("\ncount print:%d\n", j);
// 	ft_printf("-------");
// 	ft_printf("\nft_printf:");
// 	int i = ft_printf(" %c %c %c ", '0', 0, '1');
// 	ft_printf("\ncount ft:%d", i);
// }