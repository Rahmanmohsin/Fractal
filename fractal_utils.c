/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:11:25 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/07 20:06:10 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

char	*make_upper(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] > 96 && s[i] < 123)
			s[i] = ft_toupper(s[i]);
	return (s);
}

static double	ft_strtod_2(const char *str, int i)
{
	int		k;
	double	result;
	int		flag;

	k = 0;
	result = 0;
	flag = 0;
	while ((str[++i] >= 48 && str[i] <= 57) || str[i] == '.')
	{
		if (str[i] == '.')
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
			result = (result) + ((double)(str[i] - 48) / pow(10, ++k));
		else
			result = (result * 10) + ((str[i] - 48));
	}
	return (result);
}

double	ft_strtod(const char *str)
{
	int			i;
	double		sign;
	double		result;

	i = -1;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	result = ft_strtod_2(str, i);
	return (result * sign);
}
