/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:23:40 by mohrahma          #+#    #+#             */
/*   Updated: 2024/05/10 01:12:20 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

/*-----------------LIBRARIES-----------------*/
# include "FtPrintf/ft_printf.h"
# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*----------------DIMENSIONS-----------------*/
# define WIDTH 1024
# define HEIGHT 1024

/*------------------COLOURS------------------*/
# define CYAN 0x00FFFF
# define YELLOW 0xFFFF00

/*------------------STRUCTS------------------*/
typedef struct s_axis
{
	double		x;
	double		y;
}				t_axis;

typedef struct s_graph
{
	double		max_h;
	double		min_h;
	double		max_v;
	double		min_v;
}				t_graph;

typedef struct s_mandelbrot
{
	mlx_image_t	*image;
	mlx_t		*window;
	t_graph		graph;
	t_axis		z;
	t_axis		c;
	double		zoom;
	double		pixel;
	double		hype;
	int			i;
	int			interations;
}				t_mandelbrot;

typedef struct s_julia
{
	mlx_image_t	*image;
	mlx_t		*window;
	t_graph		graph;
	t_axis		set;
	t_axis		input;
	double		zoom;
	double		pixel;
	double		hype;
	int			i;
	int			interations;
}				t_julia;

/*-------------------UTILS-------------------*/
char		*make_upper(char *s);
double		ft_strtod(const char *str);
/*-------------------ERROR-------------------*/
void		error_message(void);
int			char_check(char **argv);
/*-------------------EVENTS------------------*/
void		mouse(double xdelta, double ydelta, void *param);
void		keyboard(mlx_key_data_t keydata, void *param);
void		resize_j(int32_t width, int32_t height, void *param);
void		resize_m(int32_t width, int32_t height, void *param);
/*-----------------MANDELBROT----------------*/
void		mandelbrot(t_mandelbrot *fractal);
void		mandelbrot_init(t_mandelbrot *f);
void		mandelbrot_draw(void *param);
void		mandelbrot_calc(t_mandelbrot *f, double x, double y, int c);
double		mandelbrot_colour(double point, t_mandelbrot *f);
/*--------------------JULIA-------------------*/
void		julia(t_julia *f);
void		julia_init(t_julia *f);
void		julia_draw(void *param);
void		julia_calc(t_julia *f, double x, double y, int c);
double		julia_colour(double point, t_julia *f);

# define ERROR "\n\n\033[0;91m\
██╗███╗░░██╗░█████╗░░█████╗░██████╗░██████╗░███████╗░█████╗░████████╗\n\
██║████╗░██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗╚══██╔══╝\n\
██║██╔██╗██║██║░░╚═╝██║░░██║██████╔╝██████╔╝█████╗░░██║░░╚═╝░░░██║░░░\n\
██║██║╚████║██║░░██╗██║░░██║██╔══██╗██╔══██╗██╔══╝░░██║░░██╗░░░██║░░░\n\
██║██║░╚███║╚█████╔╝╚█████╔╝██║░░██║██║░░██║███████╗╚█████╔╝░░░██║░░░\n\
╚═╝╚═╝░░╚══╝░╚════╝░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝░╚════╝░░░░╚═╝░░░\n\
              ███╗██╗░░░██╗██████╗░██╗░░░██╗████████╗\n\
              ███║█████░██║██╔══██╗██║░░░██║╚══██╔══╝\n\
              ███║██║█████║██████╔╝██║░░░██║░░░██║░░░\n\
              ███║██║░░║██║██║░░░░░╚██████╔╝░░░██║░░░\n\
              ╚═╝╚══╝░░╚══╝╚═╝░░░░░░╚═════╝░░░░╚═╝░░░\033[0;92m\n\
\n\
\n\
\n\
           █▀▄▀█ ▄▀█ █▄░█ █▀▄ █▀▀ █░░ █▄▄ █▀█ █▀█ ▀█▀\n\
           █░▀░█ █▀█ █░▀█ █▄▀ ██▄ █▄▄ █▄█ █▀▄ █▄█ ░█░\n\
             	    ./fractal mandelbrot\n\
\n\
\n\
			░░█ █░█ █░░ █ ▄▀█\n\
			█▄█ █▄█ █▄▄ █ █▀█\n\
		   ./fractal julia (X) (Y)\n\
\n\
        █▀█ █▀▀ █▀▀ █▀█ █▀▄▀█ █▀▄▀█ █▀▀ █▄░█ █▀▄ █▀▀ █▀▄\n\
        █▀▄ ██▄ █▄▄ █▄█ █░▀░█ █░▀░█ ██▄ █░▀█ █▄▀ ██▄ █▄▀\n\
\n\
             ▄▀ ▀▄▀ ▀▄   ▄▀█ █▄░█ █▀▄     ▄▀ █▄█ ▀▄\n\
             ▀▄ █░█ ▄▀   █▀█ █░▀█ █▄▀     ▀▄ ░█░ ▄▀\n\
\n\
             -0.70176                      -0.3842\n\
                0                            0.8\n\
              0.285                          0.01\n\
              -0.835                       -0.2321\n\n\
\n"

#endif