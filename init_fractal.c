/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:08:31 by milagros          #+#    #+#             */
/*   Updated: 2025/04/02 16:59:24 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void error_malloc(void)
{
    perror("Malloc Failure");
    exit(EXIT_FAILURE);
}

void    init_data(t_fractal *fractal)
{
    fractal->hypotenuse = 4; //2sqr
    fractal->iterations = 42;  
}

void    init_fractal(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init(); //check
    if(!fractal->mlx_connection)
        error_malloc();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, 
                                        fractal->name);
    if(!fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        error_malloc();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if(!fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        error_malloc();
    }
    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
                &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    init_data(fractal);
}