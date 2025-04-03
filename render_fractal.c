/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:06:55 by milagros          #+#    #+#             */
/*   Updated: 2025/04/02 16:57:02 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void put_pixel(int x, int y, t_img *img, int color)
{
    int     pixel;

    pixel = (y * img->line_len + x * (img->bpp / 8)); //pending check important
    *(unsigned int *)(img->pixels_ptr + pixel) = color; //pending check important
}

static void set_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	point;
	t_complex	init_point;
	int	        i;
    int         color;

	i = 0;
	point.real = 0.0;
	point.i = 0.0;

	init_point.real = scale(x, -2, 2, WIDTH);
    init_point.i = scale(y, 2, -2, HEIGHT);

	while (i < fractal->iterations) //check iterations
	{
        point = sum_complex(square_complex(point), init_point);

		if ((point.real * point.real) + (point.i * point.i) > fractal->hypotenuse)
        {
            color = scale(i, BLACK, WHITE, fractal->iterations); //pending to check
            put_pixel(x, y, &fractal->img, color); //pending to check
            return ;
        }
		i++;
	}
    put_pixel(x, y, &fractal->img, FLUORESCENT_ORANGE);
}

void    render_fractal(t_fractal *fractal)
{
    int x;
    int y;
    //int color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // Calculate the color for each pixel based on the fractal type
            // if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
            //     color = mandelbrot(x, y);
            // else if (ft_strncmp(fractal->name, "julia", 5) == 0)
            //     color = julia(x, y);
            // else
            //     color = 0; // Default color

            // Set the pixel color in the image
            set_pixel(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}