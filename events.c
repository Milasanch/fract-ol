/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 02:04:13 by milsanch          #+#    #+#             */
/*   Updated: 2025/04/03 22:55:06 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_plus)
		fractal->iterations += 10;
	else if (keysym == XK_minus)
		fractal->iterations -= 10;
	render_fractal(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	render_fractal(fractal);
	return (0);
}

int	track_julia(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_real = scale(x, -2, 2, WIDTH) * fractal->zoom
			+ fractal->shift_x;
		fractal->julia_i = scale(y, 2, -2, HEIGHT) * fractal->zoom
			+ fractal->shift_y;
		render_fractal(fractal);
	}
	return (0);
}
