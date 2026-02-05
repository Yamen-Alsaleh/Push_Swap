/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:29:01 by hahel             #+#    #+#             */
/*   Updated: 2025/12/14 17:27:27 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*fill_digits(char *s, long n, int len)
{
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	while (n > 0)
	{
		len--;
		s[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		len;
	char	*s;

	tmp = n;
	len = count_digits(tmp);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (tmp < 0)
	{
		s[0] = '-';
		tmp = -tmp;
	}
	s = fill_digits(s, tmp, len);
	return (s);
}
