/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:10:59 by milagros          #+#    #+#             */
/*   Updated: 2025/04/02 14:20:47 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double    scale(double unscaled_num, double new_min, double new_max,
                double old_max)
{
    double scaled_num;

    scaled_num = ((unscaled_num) * ((new_max - new_min) / old_max)) + new_min;
    return (scaled_num);
}

t_complex    sum_complex(t_complex x, t_complex y)
{
    t_complex result;

    result.real = x.real + y.real;
    result.i = x.i + y.i;
    return (result);
}

t_complex    square_complex(t_complex x)
{
    t_complex result;

    result.real = (x.real * x.real) - (x.i * x.i);
    result.i = 2 * (x.real * x.i);
    return (result);
} 