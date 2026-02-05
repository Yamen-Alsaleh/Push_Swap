/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalsaleh <yalsaleh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:54:33 by yalsaleh          #+#    #+#             */
/*   Updated: 2025/12/11 14:40:13 by yalsaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numofwords(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*word(const char *str, char c)
{
	int		i;
	char	*p;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	fill(char **p, const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			p[j] = word(&s[i], c);
			if (!p[j])
			{
				while (j > 0)
					free(p[--j]);
				free(p);
				return (1);
			}
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	p[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof (char *) * (numofwords(s, c) + 1));
	if (!p)
		return (NULL);
	if (fill(p, s, c, 0))
		return (NULL);
	return (p);
}
