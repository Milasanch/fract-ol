/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:50 by milsanch          #+#    #+#             */
/*   Updated: 2025/03/12 12:57:13 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"


// typedef struct	complex_type
// {
// 	double	real;
// 	double	i;
// }		complex_num;


int	main(void)
{
	complex_num	point;
	complex_num	init_point;
	double		tmp_real;
	int			i;

	i = 0;
	point.real = 0;
	point.i = 0;

	init_point.real = 5;
	init_point.i = 2;
	while (i < 42)
	{
		tmp_real = (point.real * point.real)- (point.i * point.i);
		point.i = 2 * (point.real * point.i);
		point.real = tmp_real + init_point.real;
		point.i += init_point.i;
		
		printf("%d real %f imaginary %f\n", i, point.real, point.i);
		i++;
	}
	return (0);
}
