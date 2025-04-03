/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:16:04 by milagros          #+#    #+#             */
/*   Updated: 2025/04/03 15:13:52 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "fractol.h"

double atodbl(char *s)
{
	long	i;
	double	fraction;
	double	pow;
	int		sign;

	i = 0;
	fraction = 0;
	sign = 1;
	pow = 1;
	while (*s >= 9 && *s <= 13 || *s == 32)
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		fraction = (fraction * 10) + (*s++ - '0');
	}
	return (sign * (i + fraction * pow));
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2  == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && (*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		n--;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

