/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:30:07 by milsanch          #+#    #+#             */
/*   Updated: 2025/03/30 18:40:09 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //chech if it should be deleted at the end
# include <unistd.h> 
# include <stdlib.h> 
# include <math.h>
# include "minilibx-linux/mlx.h" //why mlx.h?

#define ERROR_MESSAGE "Error, enter the fractal's name, it can be mandelbrot or julia " //revisar sintaxis

typedef struct	s_img
{
	void	*img; //pointer to image struct
	char	*pixels // points to the actual pixels
}

typedef struct	s_fract
{
	void	*mlx

}
typedef struct	complex_type
{
	double	real;
	double	i;
}		complex_num;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif