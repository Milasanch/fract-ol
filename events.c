/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 02:04:13 by milsanch          #+#    #+#             */
/*   Updated: 2025/04/10 20:02:00 by milsanch         ###   ########.fr       */
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
	else if (keysym == XK_space)
	{
		fractal->zoom = 1;
		fractal->shift_x = 0;
		fractal->shift_y = 0;
	}
	render_fractal(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	if (button == Button5)
		zoom_factor = 1.1;
	else if (button == Button4)
		zoom_factor = 0.9;
	else
		return (0);
	mouse_x = (scale(x, -2, 2, WIDTH) * fractal->zoom * zoom_factor)
		+ fractal->shift_x;
	mouse_y = (scale(y, -2, 2, HEIGHT) * fractal->zoom * zoom_factor)
		+ fractal->shift_y;
	fractal->zoom *= zoom_factor;
	render_fractal(fractal);
	return (0);
}
