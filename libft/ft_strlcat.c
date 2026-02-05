/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 12:46:13 by hahel             #+#    #+#             */
/*   Updated: 2025/12/14 18:50:00 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	to_copy;
	size_t	i;

	slen = ft_strlen(src);
	if (dsize == 0)
		return (slen);
	dlen = ft_strlen(dest);
	if (dlen >= dsize)
		return (dsize + slen);
	to_copy = dsize - dlen - 1;
	i = 0;
	while (i < to_copy && src[i])
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
