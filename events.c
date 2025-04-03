/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 02:04:13 by milsanch          #+#    #+#             */
/*   Updated: 2025/04/03 14:44:06 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    mlx_destroy_display(fractal->mlx_connection);
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}
int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal); //to do
    if (keysym == XK_Left)
        fractal->shift_x += 0.5;
    else if (keysym == XK_Right)
        fractal->shift_x -= 0.5;
    else if (keysym == XK_Up)
        fractal->shift_y -= 0.5;
    else if (keysym == XK_Down)
        fractal->shift_y += 0.5;
    else if (keysym == XK_plus)
        fractal->iterations += 10;
    else if (keysym == XK_minus)
        fractal->iterations -= 10;
    render_fractal(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == Button5)
    {
        fractal->zoom *= 0.90;
    }
    else if (button == Button4)
    {
        fractal->zoom *= 1.1;
    }
    render_fractal(fractal);
    return (0);
}