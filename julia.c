/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:33:57 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/13 00:52:16 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

	// double	red;
	// double	green;
	// double	blue;

	// red = 255 - 255 * sin(1 - point / f->interations);
	// green = 63 * cos(1 - (point / f->interations));
	// blue = 255 - 255 * sin(sin(point / f->interations));
	// return (((int)red << 16) | ((int)green << 8) | (int)blue);

double	julia_colour(double point, t_julia *f)
{
	if (point >= f->interations * 0.20)
		return (YELLOW * cos(point) * f->interations);
	// return (255);
	return (CYAN * cos(point) * f->interations);
}

void	julia_calc(t_julia *f, double x, double y, int c)
{
	double	temp;

	if (c == 1)
	{
		f->set.x = f->graph.min_h + x / f->window->width * (f->graph.max_h
				- f->graph.min_h);
		f->set.y = f->graph.min_v + y / f->window->height * (f->graph.max_v
				- f->graph.min_v);
		f->i = 0;
	}
	if (c == 2)
	{
		temp = f->set.x;
		f->set.x = f->set.x * f->set.x - f->set.y * f->set.y + f->input.x;
		f->set.y = 2 * temp * f->set.y + f->input.y;
		f->i++;
	}
}

void	julia_draw(void *param)
{
	double		x;
	double		y;
	t_julia		*f;

	f = (t_julia *)param;
	y = -1;
	while (++y < f->window->height)
	{
		x = -1;
		while (++x < f->window->width)
		{
			mlx_put_pixel(f->image, x, y, 255);
			julia_calc(f, x, y, 1);
			while (f->i < f->interations && pow(f->set.x, 2)
				+ pow(f->set.y, 2) <= f->hype)
				julia_calc(f, x, y, 2);
			f->pixel = julia_colour(f->i, f);
			mlx_put_pixel(f->image, x, y, f->pixel);
		}
	}
}

void	julia_init(t_julia *f)
{
	f->zoom = 1;
	f->hype = 4;
	f->interations = 100;
	f->graph.max_h = 2;
	f->graph.max_v = 2;
	f->graph.min_h = -2;
	f->graph.min_v = -2;
	mlx_loop_hook(f->window, &julia_draw, f);
}

void	julia(t_julia *f)
{
	f->window = mlx_init(WIDTH, HEIGHT, "JULIA", true);
	if (f->window == NULL)
		exit(EXIT_FAILURE);
	f->image = mlx_new_image(f->window, WIDTH, HEIGHT);
	if (mlx_image_to_window(f->window, f->image, 0, 0) == -1
		|| f->image == NULL)
		return (mlx_close_window(f->window), mlx_strerror(mlx_errno),
			exit(EXIT_FAILURE));
	mlx_key_hook(f->window, keyboard, f);
	mlx_scroll_hook(f->window, mouse, f);
	mlx_resize_hook(f->window, resize_j, f);
	julia_init(f);
	mlx_loop(f->window);
	mlx_terminate(f->window);
}
