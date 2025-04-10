/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:44:25 by milsanch          #+#    #+#             */
/*   Updated: 2025/04/10 21:59:14 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_error(void)
{
	ft_putstr_fd(ERROR_PART1 ERROR_PART2, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp (argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "burningship", 11)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			if (!ft_isdouble(argv[2]) || !ft_isdouble(argv[3]))
				exit_error();
			fractal.julia_real = atodbl(argv[2]);
			fractal.julia_i = atodbl(argv[3]);
		}
		init_fractal(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		exit_error();
	return (0);
}
