#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	complex_type
{
	double	real;
	double	i;
}		complex_num;

int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif