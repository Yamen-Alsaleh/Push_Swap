/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:27:19 by hahel             #+#    #+#             */
/*   Updated: 2025/12/17 05:07:18 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t n)
{
	size_t			i;
	unsigned char	*cstr;

	cstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		cstr[i] = (unsigned char)x;
		i++;
	}
	return (str);
}
