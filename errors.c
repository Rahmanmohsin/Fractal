/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:41:58 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/09 02:01:31 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	error_message(void)
{
	ft_printf(ERROR);
	exit(EXIT_FAILURE);
}

int	char_check(char **argv)
{
	int	i;

	i = -1;
	while (argv[2][++i] != '\0')
		if ((argv[2][i] < 48 || argv[2][i] > 57) && argv[2][i] != '.'
			&& argv[2][i] != '-')
			return (0);
	i = -1;
	while (argv[3][++i] != '\0')
		if ((argv[3][i] < 48 || argv[3][i] > 57) && argv[3][i] != '.'
			&& argv[3][i] != '-')
			return (0);
	return (1);
}
