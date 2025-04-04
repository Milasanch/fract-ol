/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:25 by milsanch          #+#    #+#             */
/*   Updated: 2025/04/03 22:44:43 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Create Julia and Mandelbrot
//Infinite Zoom
//Able to take command line args to discipline which fractal render
//ESC closes the process with no leaks
//Click on the X window, closes the process leaks free

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
	|| (argc == 4 && !ft_strncmp (argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if(!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_real = atodbl(argv[2]);
			fractal.julia_i = atodbl(argv[3]);
		}
		init_fractal(&fractal);
		
		render_fractal(&fractal);

		mlx_loop(fractal.mlx_connection); //tocheck
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);//pending check
		exit(EXIT_FAILURE);
	}
	return (0);
}