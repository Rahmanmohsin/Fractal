/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:23:49 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/09 01:31:04 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char **argv)
{
	t_mandelbrot	fractal_m;
	t_julia			fractal_j;

	if (argc > 1)
		argv[1] = make_upper(argv[1]);
	if ((argc == 2 && ft_strncmp(argv[1], "MANDELBROT", 10) == 0) || (argc == 4
			&& ft_strncmp(argv[1], "JULIA", 5) == 0 && char_check(argv) != 0))
	{
		if (ft_strncmp(argv[1], "MANDELBROT", 10) == 0)
			mandelbrot(&fractal_m);
		else
		{
			fractal_j.input.x = ft_strtod(argv[2]);
			fractal_j.input.y = ft_strtod(argv[3]);
			julia(&fractal_j);
		}
	}
	else
		error_message();
}
