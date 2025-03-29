#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //TODO debugging
# include <unistd.h> //write
# include <stdlib.h> //malloc free
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Error\n" //revisar


typedef struct	complex_type
{
	double	real;
	double	i;
}		complex_num;

int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif