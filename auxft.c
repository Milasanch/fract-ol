/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:16:04 by milagros          #+#    #+#             */
/*   Updated: 2025/04/10 21:57:38 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	ft_isdouble(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] && s[i] <= '9' && s[i] >= '0')
		i++;
	if (s[i] == '.')
		i++;
	while (s[i] && s[i] <= '9' && s[i] >= '0')
		i++;
	if (s[i] != '\0')
		return (false);
	return (true);
}

static double	aux_atodbl(char *s)
{
	double	fraction;
	double	res;

	fraction = 0;
	res = 1;
	if (*s == '.')
		s++;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		res /= 10;
		fraction = (fraction * 10) + (*s++ - '0');
	}
	return (fraction * res);
}

double	atodbl(char *s)
{
	long		i;
	int			sign;
	double		fraction;

	i = 0;
	fraction = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s != '.' && (*s >= '0' && *s <= '9'))
		i = (i * 10) + (*s++ - '0');
	fraction = aux_atodbl(s);
	return (sign * (i + fraction));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
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
