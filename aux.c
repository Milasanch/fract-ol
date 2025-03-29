/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milagros <milagros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:16:04 by milagros          #+#    #+#             */
/*   Updated: 2025/03/29 11:14:10 by milagros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2  == NULL || n<= 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void    putstr_fd(char *s, int fd)
{
    if (s == NULL || fd < 0)
        return ;
    if (*s != '\0')
    {
        write(fd, s, 1);
        putstr_fd(s + 1, fd);
    }
}
