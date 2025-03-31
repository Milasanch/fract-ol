/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:25 by milsanch          #+#    #+#             */
/*   Updated: 2025/03/31 13:31:31 by milsanch         ###   ########.fr       */
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
	t_fract	fractal;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4 
	&& !ft_strncmp (argv[1], "julia", 5)))
	{
		//kick off function
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);//pending check
		exit(EXIT_FAILURE);//pending check
	}
	return (0);
}