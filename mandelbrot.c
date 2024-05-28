/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 00:33:36 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/06 00:16:10 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// double	mandelbrot_colour(double point, t_mandelbrot *f)
// {
// 	if (point >= f->interations * 0.10)
// 		return (YELLOW * sin(point) * f->interations);
// 	return (CYAN * cos(point) * f->interations);
// }

double	mandelbrot_colour(double point, t_mandelbrot *f)
{
	double	red;
	double	green;
	double	blue;

	red = 255 - 255 * sin(1 - point / f->interations);
	green = 63 * cos(1 - (point / f->interations));
	blue = 255 - 255 * sin(sin(point / f->interations));
	return (((int)red << 16) | ((int)green << 8) | (int)blue);
}

void	mandelbrot_calc(t_mandelbrot *f, double x, double y, int c)
{
	double	temp;

	if (c == 1)
	{
		f->c.x = f->graph.min_h + x / f->window->width * (f->graph.max_h
				- f->graph.min_h);
		f->c.y = f->graph.min_v + y / f->window->height * (f->graph.max_v
				- f->graph.min_v);
		f->z.x = 0;
		f->z.y = 0;
		f->i = 0;
	}
	if (c == 2)
	{
		temp = f->z.x;
		f->z.x = pow(f->z.x, 2) - pow(f->z.y, 2) + f->c.x;
		f->z.y = 2 * temp * f->z.y + f->c.y;
		if (pow(f->z.x, 2) + pow(f->z.y, 2) <= f->hype)
		{
			f->pixel = mandelbrot_colour(f->i, f);
			mlx_put_pixel(f->image, x, y, f->pixel);
		}
		f->i++;
	}
}

void	mandelbrot_draw(void *param)
{
	double			x;
	double			y;
	t_mandelbrot	*f;

	f = (t_mandelbrot *)param;
	y = -1;
	while (++y < f->window->height)
	{
		x = -1;
		while (++x < f->window->width)
		{
			mandelbrot_calc(f, x, y, 1);
			while (f->i < f->interations)
				mandelbrot_calc(f, x, y, 2);
		}
	}
}

void	mandelbrot_init(t_mandelbrot *f)
{
	f->zoom = 1;
	f->hype = 10;
	f->interations = 50;
	f->graph.max_h = 1.5;
	f->graph.max_v = 2;
	f->graph.min_h = -2.5;
	f->graph.min_v = -2;
	mlx_loop_hook(f->window, &mandelbrot_draw, f);
}

void	mandelbrot(t_mandelbrot *f)
{
	f->window = mlx_init(WIDTH, HEIGHT, "MANDELBROT", true);
	if (f->window == NULL)
		exit(EXIT_FAILURE);
	f->image = mlx_new_image(f->window, WIDTH, HEIGHT);
	if (mlx_image_to_window(f->window, f->image, 0, 0) == -1
		|| f->image == NULL)
		return (mlx_close_window(f->window), mlx_strerror(mlx_errno),
			exit(EXIT_FAILURE));
	mlx_key_hook(f->window, keyboard, f);
	mlx_scroll_hook(f->window, mouse, f);
	mlx_resize_hook(f->window, resize_m, f);
	mandelbrot_init(f);
	mlx_loop(f->window);
	mlx_terminate(f->window);
}
