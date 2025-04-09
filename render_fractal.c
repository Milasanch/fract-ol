/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:06:55 by milagros          #+#    #+#             */
/*   Updated: 2025/04/09 00:50:18 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

static void	put_pixel(int x, int y, t_img *img, int color)
{
    int	pixel;

    pixel = (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + pixel) = color;
}

static void	fractal_type(t_complex *point, t_complex *init_point,
    t_fractal *fractal)
{
    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        init_point->real = fractal->julia_real;
        init_point->i = fractal->julia_i;
    }
    else
    {
        init_point->real = point->real;
        init_point->i = point->i;
    }
}

static int	calculate_iterations(t_complex point, t_complex init_point, 
                t_fractal *fractal)
{
    int	i;

    i = -1;
    while (++i < fractal->iterations)
    {
        if (!ft_strncmp(fractal->name, "burningship", 11))
        {
            point.real = fabs(point.real);
            point.i = fabs(point.i);
        }
        point = sum_complex(square_complex(point), init_point);
        if ((point.real * point.real + point.i * point.i) > fractal->hypotenuse)
            return (i);
    }
    return (-1);
}

static void	set_pixel(int x, int y, t_fractal *fractal)
{
    t_complex	point;
    t_complex	init_point;
    int			i;

    point.real = scale(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
    point.i = scale(y, !ft_strncmp(fractal->name, "burningship", 11) ? -2 : 2, 
        !ft_strncmp(fractal->name, "burningship", 11) ? 2 : -2, HEIGHT) 
        * fractal->zoom + fractal->shift_y;
    fractal_type(&point, &init_point, fractal);
    i = calculate_iterations(point, init_point, fractal);
    if (i >= 0)
        put_pixel(x, y, &fractal->img, scale(i, BLACK, WHITE, fractal->iterations));
    else
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
