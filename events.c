/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:52:42 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/09 08:13:43 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	keyboard(mlx_key_data_t keydata, void *param)
{
	t_mandelbrot	*f;

	f = (t_mandelbrot *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		return (mlx_delete_image(f->window, f->image),
			mlx_close_window(f->window));
}

void	mouse(double xdelta, double ydelta, void *param)
{
	t_mandelbrot	*f;

	(void)xdelta;
	f = (t_mandelbrot *)param;
	if (ydelta > 0)
		f->zoom = 1.25;
	else
		f->zoom = 0.75;
	f->graph.max_v = f->graph.max_v * f->zoom;
	f->graph.min_v = f->graph.min_v * f->zoom;
	f->graph.max_h = f->graph.max_h * f->zoom;
	f->graph.min_h = f->graph.min_h * f->zoom;
	if (f->interations > 200)
		f->interations = 100;
	else
		f->interations = f->interations + f->zoom * 10;
}

void	resize_m(int32_t width, int32_t height, void *param)
{
	t_mandelbrot	*f;

	f = (t_mandelbrot *)param;
	mlx_delete_image(f->window, f->image);
	f->image = mlx_new_image(f->window, width, height);
	if (mlx_image_to_window(f->window, f->image, 0, 0) == -1
		|| f->image == NULL)
		return (mlx_close_window(f->window), mlx_strerror(mlx_errno),
			exit(EXIT_FAILURE));
	mandelbrot_init(f);
}

void	resize_j(int32_t width, int32_t height, void *param)
{
	t_julia	*f;

	f = (t_julia *)param;
	mlx_delete_image(f->window, f->image);
	f->image = mlx_new_image(f->window, width, height);
	if (mlx_image_to_window(f->window, f->image, 0, 0) == -1
		|| f->image == NULL)
		return (mlx_close_window(f->window), mlx_strerror(mlx_errno),
			exit(EXIT_FAILURE));
	julia_init(f);
}
