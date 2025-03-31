/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:30:07 by milsanch          #+#    #+#             */
/*   Updated: 2025/03/31 13:29:04 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //erase at the end
# include <unistd.h> 
# include <stdlib.h> 
# include <math.h>
# include "minilibx-linux/mlx.h" //why mlx.h?

#define ERROR_MESSAGE "Error, enter the fractal's name, it can be mandelbrot or julia <value1> <value2>'\n"

typedef struct	s_complex
{
	double	real;
	double	i;
}		t_complex;

typedef struct	s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr // points to the actual pixels
	int		bpp;
	int		endian; // revisar
	int		line_len; //revisar
}		t_img;

typedef struct	s_fract
{
	void	*mlx_connection; //mlx_init
	void	*mlx_window; //mlx_new_window
	t_img	img;
}		t_fract;


int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif