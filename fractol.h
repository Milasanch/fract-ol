/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:30:07 by milsanch          #+#    #+#             */
/*   Updated: 2025/04/03 22:33:54 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h> 
# include <stdlib.h> 
# include <math.h>
# include <X11/X.h> //to check
# include <X11/keysym.h> //to check
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Error, enter the fractal's name, it can be mandelbrot or julia <value1> <value2>'\n"
# define WIDTH				400
# define HEIGHT				400
# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN   			0x00FF00
# define BLUE    			0x0000FF
# define FLUORESCENT_PINK	0xFF1493
# define FLUORESCENT_GREEN	0x39FF14
# define FLUORESCENT_YELLOW	0xFFFF00
# define FLUORESCENT_ORANGE	0xFFA500
# define FLUORESCENT_BLUE	0x00FFFF
# define FLUORESCENT_PURPLE	0xBF00FF

typedef struct s_complex
{
	double	real;
	double	i;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian; //check
	int		line_len; //check
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection; //mlx_init
	void	*mlx_window; //mlx_new_window
	t_img	img;
	double	hypotenuse;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_real;
	double	julia_i;
}		t_fractal;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		atodbl(char *s);
void		init_fractal(t_fractal *fractal);
double		scale(double unscaled_num, double new_max, double old_min,
				double old_max);
t_complex	sum_complex(t_complex x, t_complex y);
t_complex	square_complex(t_complex x);
void		render_fractal(t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			track_julia(int x, int y, t_fractal *fractal);
#endif