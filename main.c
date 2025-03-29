/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:25 by milsanch          #+#    #+#             */
/*   Updated: 2025/03/29 11:14:10 by milagros         ###   ########.fr       */
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
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) || 4 == argv 
	&& !ft_strncmp (argv[1], "julia", 5)
	{
		//Promp correct
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO) //revisar
		exit(EXIT_FAILURE);//revisar
	}
	return (0);
}