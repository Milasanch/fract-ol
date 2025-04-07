/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:06:55 by milagros          #+#    #+#             */
/*   Updated: 2025/04/07 22:52:59 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(int x, int y, t_img *img, int color)
{
	int	pixel;

	pixel = (y * img->line_len + x * (img->bpp / 8)); //pending check important
	*(unsigned int *)(img->pixels_ptr + pixel) = color; //pending check important
}

static void	fractal_type(t_complex *point, t_complex *init_point,
	t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		init_point->real = fractal->julia_real;
		init_point->i = fractal->julia_i;
	}
	else if (!ft_strncmp(fractal->name, "burningship", 11))
	{
		init_point->real = fabs(point->real);
		init_point->i = fabs(point->i);
	}
	else
	{
		init_point->real = point->real;
		init_point->i = point->i;
	}
}

static void	set_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	point;
	t_complex	init_point;
	int			i;
	int			color;

	i = 0;
	point.real = scale(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	point.i = scale(y, 2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
	fractal_type(&point, &init_point, fractal);
	while (i < fractal->iterations) //check iterations
	{
		point = sum_complex(square_complex(point), init_point);
		if ((point.real * point.real) + (point.i * point.i) >
			fractal->hypotenuse)
		{
			color = scale(i, BLACK, WHITE, fractal->iterations); //pending to check
			put_pixel(x, y, &fractal->img, color); //pending to check
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractal->img, FLUORESCENT_ORANGE);
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
