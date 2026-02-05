/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahel <hayat.ahel@learner.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:32:46 by hahel             #+#    #+#             */
/*   Updated: 2025/12/17 14:30:40 by hahel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	f_size;

	if (!s1 || !s2)
		return (NULL);
	f_size = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(f_size + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, f_size + 1);
	ft_strlcat(join, s2, f_size + 1);
	return (join);
}
