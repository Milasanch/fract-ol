/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:50 by milsanch          #+#    #+#             */
/*   Updated: 2025/03/10 18:21:31 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fract-ol.h";


typedef struct	complex_type
{
	double	real;
	double	i;
}		complex_num;


int	main
{
	complex_num	point;
	complex_num	init_point;
	double		tmp_real;
	int			i;

	i = 0;
	point.real = 0;
	pont.i = 0;

	init_point.real = 5;
	init_point.i = 2;
	while (i < 42)
	{
		tmp_real = (point.real * point.real)- (point.i * point.i);
		point.i = 2 * (point.real * point.i)
	//General formula
	// z= z² + c
	}
	return (0);
}
