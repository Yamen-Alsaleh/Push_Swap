/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:31:14 by hahel             #+#    #+#             */
/*   Updated: 2025/12/17 06:28:46 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ms;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ms = malloc(len + 1);
	if (!ms)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ms[i] = f(i, s[i]);
		i++;
	}
	ms[i] = '\0';
	return (ms);
}
