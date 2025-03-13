/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milsanch <milsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:02:31 by milsanch          #+#    #+#             */
/*   Updated: 2025/03/12 16:59:03 by milsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char	*s1 = "test\200";
	const char	*s2 = "test\0";
	size_t		n;

	n = 6;
	printf("%i\n", ft_strncmp(s1, s2, n));
	//printf("%i\n", strncmp(s1, s2, n));
	return (0);
}*/
