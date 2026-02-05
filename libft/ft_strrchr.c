/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:39:30 by hahel             #+#    #+#             */
/*   Updated: 2025/12/17 06:36:41 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	x;
	char	*y;

	x = (char)c;
	y = NULL;
	i = 0;
	while (1)
	{
		if (s[i] == x)
			y = (char *)&s[i];
		if (s[i] == '\0')
			return (y);
		i++;
	}
}
