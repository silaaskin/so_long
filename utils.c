/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:47:34 by saskin            #+#    #+#             */
/*   Updated: 2025/04/10 11:39:18 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)b;
	while (i < len)
	{
		*(s + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

static int	ft_digitcount(int n, int sign)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	if (sign < 0)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		sign;
	int		digitcount;

	number = n;
	sign = 1;
	if (number < 0)
		sign = -1;
	number = sign * number;
	digitcount = ft_digitcount(number, sign);
	str = (char *)malloc(sizeof(char) * digitcount + 1);
	if (!str)
		return (0);
	str[digitcount] = '\0';
	while (--digitcount >= 0)
	{
		str[digitcount] = (number % 10) + '0';
		number = number / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
