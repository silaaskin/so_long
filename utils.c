/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saskin <saskin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:47:34 by saskin            #+#    #+#             */
/*   Updated: 2025/04/09 04:14:07 by saskin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t sstrlen(const char *s)
{
    size_t i = 0;
   while (s[i] && s[i] != '\n')
        i++;
    return (i);
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	char	*newsrc;
// 	int		l;

// 	i = 0;
// 	l = 0;
// 	while (s1[l])
// 		l++;
// 	newsrc = (char *)malloc((l + 1) * sizeof(char));
// 	if (!(newsrc))
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		newsrc[i] = s1[i];
// 		i++;
// 	}
// 	newsrc[i] = '\0';
// 	return (newsrc);
// }
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
static int	ft_digitcount(int n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (sign < 0)
		i++;
	return (i);
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