/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:00:50 by hahel             #+#    #+#             */
/*   Updated: 2025/12/14 18:41:43 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*y;

	x = (unsigned char)c;
	y = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (y[i] == x)
			return (&y[i]);
		i++;
	}
	return (NULL);
}
